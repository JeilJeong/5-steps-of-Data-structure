
//function_name		input		output

//createList()		n		list
//deleteList()		list		n/a
//isFull()		list		True/False
//addElement()		list, p, e	success or fail return value
//removeElement()	list, p		success or fail return value
//clearList()		list		n/a
//getListLength()	list		number of element
//getElement()		list, p		e

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
	free(list->pElement);
	free(list);
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
	deleteEelem
}

int main()
{
	ArrayList	*list;
	list = createList(4);
//	deleteList(list);
//	ArrayListNode tmp;
//	tmp.data = 1;
//	printf("%d\n", addElement(list, 0, tmp));
//	printf("%d\n", addElement(list, 1, tmp));
//	printf("%d\n", addElement(list, 2, tmp));
//	printf("%d\n", addElement(list, 3, tmp));
//	printf("%d\n", addElement(list, 4, tmp));
}
