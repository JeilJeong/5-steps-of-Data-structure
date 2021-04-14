#include "../includes/ft_tree.h"

int		count = 0;

int		main()
{
	t_tree	*root;
	t_tree	*node;
	int		data;
	int		i;

	i = 0;
	root = NULL;
	srand((unsigned int)time(NULL));
	while (i < 10)
	{
		data = rand() % 100;
		node = ft_create_node(data);
		printf("[%d] ", node->data);
		count += ft_insert_node(&root, node);
		i++;
	}
	printf("\n");
	printf("********************PRE_ORDER********************\n");
	ft_print_tree(root, PRE_ORDER);
	printf("\n");
	printf("********************IN_ORDER********************\n");
	ft_print_tree(root, IN_ORDER);
	printf("\n");
	printf("********************POST_ORDER********************\n");
	ft_print_tree(root, POST_ORDER);
	printf("\n");
}