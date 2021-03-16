#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "a_list.h"

ArrayList	*createList(int maxElementCount)
{
	ArrayList	*list;
	int		i;

	list = NULL;
	i = 0;
	if (maxElementCount > 0)
	{
		if ((list = (ArrayList *)malloc(sizeof(ArrayList))) == NULL)
		{
			perror("ArrayList malloc error");
			return (NULL);
		}
		list->maxElementCount = maxElementCount;
		list->currentElementCount = 0;
		list->pElement = NULL;
	}
	else
	{
		perror("maxElementCount is less than 0");
		return (NULL);
	}
	if ((list->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount)) == NULL)
	{
		perror("ArrayListNode malloc error");
		free(list);
		return (NULL);
	}
	memset(list->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
	return (list);
}

void	deleteList(ArrayList *list)
{
	if (list != NULL)
	{
		free(list->pElement);
		free(list);
	}
}

int	isFull(ArrayList *list)
{
	if (list->currentElementCount == list->maxElementCount)
		return (TRUE);
	return (FALSE);
}

int	addElement(ArrayList *list, int p, ArrayListNode e)
{
	int	i;
	
	i = 0;
	if (list != NULL)
	{

		if (isFull(list) == TRUE)
		{
			perror("list is full");
			return (FALSE);
		}
		if (p < 0 || p > list->currentElementCount)
		{
			perror("list index is not valid");
			return (FALSE);
		}
		for (i = list->currentElementCount - 1; i >= p; i--)
			list->pElement[i + 1] = list->pElement[i];
		list->pElement[p] = e;
		list->currentElementCount++;
		return (TRUE);
	}
	return (FALSE);
}

int	deleteElement(ArrayList *list, int p)
{
	int	i;

	i = 0;
	if (list != NULL)
	{
		if (p < 0 || p >= list->currentElementCount)
		{
			perror("deletElement position is not valid");
			return (FALSE);
		}
		for (i = p; i < list->currentElementCount - 1; i++)
			list->pElement[i] = list->pElement[i + 1];
		list->currentElementCount--;
		return (TRUE);
	}
	return (FALSE);
}

ArrayListNode	*getElement(ArrayList *list, int p)
{
	ArrayListNode *pReturn;

	pReturn = NULL;
	if (list != NULL)
	{
		if (p < 0 || p >= list->currentElementCount)
			perror("getElement position is not vaild");
		else
			pReturn = &(list->pElement[p]);
	}
	return (pReturn);
}

int main(void)
{
	ArrayList	*list;
	list = createList(4);
	ArrayListNode tmp;
	ArrayListNode tmp1;
	ArrayListNode tmp2;
	ArrayListNode tmp3;
	tmp.data = 1;
	tmp1.data = 2;
	tmp2.data = 3;
	tmp3.data = 4;
	printf("%d\n", addElement(list, 0, tmp));
	printf("%d\n", addElement(list, 1, tmp1));
	printf("%d\n", addElement(list, 2, tmp2));
	printf("%d\n", addElement(list, 3, tmp3));
	printf("%d\n", addElement(list, 4, tmp));
	printf("%d\n", deleteElement(list, 0));
	printf("list[0] = %d\n", *(getElement(list, 0)));
	deleteList(list);
}
