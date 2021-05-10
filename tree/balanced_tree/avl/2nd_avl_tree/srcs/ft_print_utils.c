#include "../includes/ft_avl.h"

void	ft_println(int i)
{
	while (i--)
		printf("\n");
}

void	ft_print_tree(t_tree *root, int count)
{
	int		input;

	while (1)
	{
		input = 0;
		printf("	*** PRINT MODE ***\n");
		printf("	[1] PRE_ORDER\n");
		printf("	[2] IN_ORDER\n");
		printf("	[3] POST_ORDER\n");
		printf("	[4] LEVEL\n");
		printf("	[5] BACK TO MAIN\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == PRE_ORDER)
		{
			printf("	PRE_ORDER: ");
			ft_tree_traversal(root, PRE_ORDER);
		}
		else if (input == IN_ORDER)
		{
			printf("	IN_ORDER: ");
			ft_tree_traversal(root, IN_ORDER);
		}
		else if (input == POST_ORDER)
		{
			printf("	POST_ORDER: ");
			ft_tree_traversal(root, POST_ORDER);
		}
		else if (input == LEVEL)
		{
			printf("	LEVEL_TRAVERSAL: ");
			ft_level_traversal(root);
		}
		else if (input == 5)
			break;
		ft_println(1);
		printf("	Node Count: %d\n", count);
		ft_println(1);
	}
}

void	ft_tree_traversal(t_tree *root, int order)
{
	if (!root)
		return ;
	if (order == PRE_ORDER)
	{
		printf("%d ", root->data);
		ft_tree_traversal(root->left, order);
		ft_tree_traversal(root->right, order);
	}
	else if (order == IN_ORDER)
	{
		ft_tree_traversal(root->left, order);
		printf("%d ", root->data);
		ft_tree_traversal(root->right, order);
	}
	if (order == POST_ORDER)
	{
		ft_tree_traversal(root->left, order);
		ft_tree_traversal(root->right, order);
		printf("%d ", root->data);
	}
}

void	ft_level_traversal(t_tree *root)
{
	t_queue		*queue;
	t_node		*node;

	queue = NULL;
	if (!root)
		return ;
	if (!(queue = ft_create_queue()))
	{
		printf("alloc error: ft_create_queue called by ft_level_travesal\n");
		return ;
	}
	ft_enqueue(queue, root);
	while (queue->front)
	{
		node = ft_dequeue(queue);
		printf("%d ", node->tree_node->data);
		if (node->tree_node->left)
			ft_enqueue(queue, node->tree_node->left);
		if (node->tree_node->right)
			ft_enqueue(queue, node->tree_node->right);
		free(node);
	}
	free(queue);
}