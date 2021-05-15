#include "../includes/ft_avl.h"

void	ft_println(int size)
{
	while (size-- > 0)
		printf("\n");
}

void	ft_print_tree_mode(t_tree *root, int count)
{
	int		input;

	if (!root)
		return ;
	while (1)
	{
		input = 0;
		ft_println(1);
		printf("	---- PRINT MODE ----\n");
		printf("	<1> PRE    ORDER\n");
		printf("	<2> IN     ORDER\n");
		printf("	<3> POST   ORDER\n");
		printf("	<4> LEVEL  TRAVE\n");
		printf("	<5> RETURN TO SUB\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == PRE_ORDER)
		{
			printf("	PRE_ORDER: ");
			ft_print_node(root, PRE_ORDER);
			ft_println(1);
			printf("	NODE COUNT: %d\n", count);
		}
		else if (input == IN_ORDER)
		{
			printf("	IN_ORDER: ");
			ft_print_node(root, IN_ORDER);
			ft_println(1);
			printf("	NODE COUNT: %d\n", count);
		}
		else if (input == POST_ORDER)
		{
			printf("	POST_ORDER: ");
			ft_print_node(root, POST_ORDER);
			ft_println(1);
			printf("	NODE COUNT: %d\n", count);
		}
		else if (input == LEVEL_TRAV)
		{
			printf("	LEVEL_TRAV: ");
			ft_level_trav(root);
			ft_println(1);
			printf("	NODE COUNT: %d\n", count);
		}
		else if (input == 5)
			return ;
	}
}

void	ft_print_node(t_tree *root, int order)
{
	if (!root)
		return ;
	if (order == PRE_ORDER)
	{
		printf("%d ", root->data);
		ft_print_node(root->left, order);
		ft_print_node(root->right, order);
	}
	else if (order == IN_ORDER)
	{
		ft_print_node(root->left, order);
		printf("%d ", root->data);
		ft_print_node(root->right, order);
	}
	else if (order == POST_ORDER)
	{
		ft_print_node(root->left, order);
		ft_print_node(root->right, order);
		printf("%d ", root->data);
	}
}

void	ft_level_trav(t_tree *root)
{
	t_queue	*queue;
	t_node	*node;

	if (!root)
		return ;
	while (!(queue = ft_create_queue()))
		printf("alloc error: ft_create_queue called by ft_level_trav\n");
	ft_enqueue(queue, root);
	while (queue->count != 0)
	{
		if (!(node = ft_dequeue(queue)))
			return ;
		printf("%d ", node->tree_node->data);
		if (node->tree_node->left)
			ft_enqueue(queue, node->tree_node->left);
		if (node->tree_node->right)
			ft_enqueue(queue, node->tree_node->right);
	}
}