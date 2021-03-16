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

#define TRUE 1
#define FALSE 0

#endif
