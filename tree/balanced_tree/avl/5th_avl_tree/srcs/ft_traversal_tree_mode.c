#include "../includes/ft_avl.h"

void	ft_traversal_tree_mode(t_tree *root, int count)
{
	int		input;

	input = 0;
	if (!root)
		return ;
	while (1)
	{
		ft_println(1);
		printf("+++[Trav Mode]+++\n");
		printf("(1) Pre -Order Trav\n");
		printf("(2) IN  -Order Trav\n");
		printf("(3) Post-Order Trav\n");
		printf("(4) Level      Trav\n");
		printf("(5) Return To  Menu\n");
		printf(">>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 5)
			break;
		else if (input == 1)
		{
			printf("Pre-Order: ");
			ft_basic_trav_tree(root, input);
		}
		else if (input == 2)
		{
			printf("In-Order: ");
			ft_basic_trav_tree(root, input);
		}
		else if (input == 3)
		{
			printf("Post-Order: ");
			ft_basic_trav_tree(root, input);
		}
		else if (input == 4)
		{
			printf("Level Trav: ");
			ft_level_trav_tree(root);
		}
		ft_println(1);
		printf("Count: %d\n", count);
	}
}

void	ft_basic_trav_tree(t_tree *root, int order)
{
	if (!root)
		return ;
	if (order == PRE_ORDER)
	{
		printf("%d ", root->data);
		ft_basic_trav_tree(root->left, order);
		ft_basic_trav_tree(root->right, order);
	}
	else if (order == IN_ORDER)
	{
		ft_basic_trav_tree(root->left, order);
		printf("%d ", root->data);
		ft_basic_trav_tree(root->right, order);
	}
	else if (order == POST_ORDER)
	{
		ft_basic_trav_tree(root->left, order);
		ft_basic_trav_tree(root->right, order);
		printf("%d ", root->data);
	}
}

void	ft_level_trav_tree(t_tree *root)
{
	t_queue *queue;
	t_node	*node;

	queue = NULL;
	node = NULL;
	if (!root)
		return ;
	queue = ft_create_queue();
	ft_enqueue(queue, root);
	while (queue->front)
	{
		if ((node = ft_dequeue(queue)))
		{
			printf("%d ", node->tree_node->data);
			if (node->tree_node)
			{
				if (node->tree_node->left)
					ft_enqueue(queue, node->tree_node->left);
				if (node->tree_node->right)
					ft_enqueue(queue, node->tree_node->right);
			}
		}
		free(node);
		node = NULL;
	}
	free(queue);
	queue = NULL;
}