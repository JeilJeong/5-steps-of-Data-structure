//function_name		input		output

//createList()		n		list
//deleteList()		list		n/a
//isFull()		list		True/False
//addElement()		list, p, e	success or fail return value
//removeElement()	list, p		success or fail return value
//clearList()		list		n/a
//getListLength()	list		number of element
//getElement()		list, p		e

#ifndef A_LIST
# define A_LIST

typedef struct ArrayListNodeType
{
	int	data;
} ArrayListNode;

typedef struct ArrayListType
{
	int	maxElementCount;
	int	currentElementCount;
	ArrayListNode *pElement;
} ArrayList;

ArrayList	*createList(int maxElementCount);
void	deleteList(ArrayList *list);
int	isFull(ArrayList *list);
int	addElement(ArrayList *list, int p, ArrayListNode e);
int	deleteElement(ArrayList *list, int p);
ArrayListNode	*getElement(ArrayList *list, int p);

#define TRUE 1
#define FALSE 0

#endif
