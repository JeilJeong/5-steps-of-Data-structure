#include "../includes/ft_avl.h"

void	ft_search_node_mode(t_tree *root)
{
	int		input;
	int		data;
	t_tree	*node;

	input = 0;
	data = 0;
	if (!root)
		return ;
	while (1)
	{
		ft_println(1);
		printf("	--------[Search Menu]--------\n");
		printf("	(1) Type    Data\n");
		printf("	(2) Back to Menu\n");
		printf("	>>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("	Data: ");
			scanf("%d", &data);
			node = ft_search_tree_node(root, data);
			if (!node)
				printf("	[%d] node doesn't exist in tree\n", data);
			else
			{
				printf("	[%d] node exist in tree\n", data);
				if (node->parent)
				{
					printf("	<Parent> Data: %d\n", node->parent->data);
					if (node->parent->left)
						printf("	<Parent->left> Data: %d\n", node->parent->left->data);
					else
						printf("	<Parent->left> NULL\n");
					if (node->parent->right)
						printf("	<Parent->right> Data: %d\n", node->parent->right->data);
					else
						printf("	<Parent->right> NULL\n");
				}
				else
					printf("	<Parent> NULL\n");
				if (node->left)
				{
					printf("	<Left> Data: %d\n", node->left->data);
					if (node->left->parent)
						printf("	<Left->Parent> Data: %d\n", node->left->parent->data);
					else
						printf("	<Left->Parent> NULL\n");
				}
				else
					printf("	<Left> NULL\n");
				if (node->right)
				{
					printf("	<Right> Data: %d\n", node->right->data);
					if (node->right->parent)
						printf("	<Right->Parent> Data: %d\n", node->right->parent->data);
					else
						printf("	<Right->Parent> NULL\n");
				}
				else
					printf("	<Right> NULL\n");
			}
		}
		else if (input == 2)
			break;
	}
}

t_tree	*ft_search_tree_node(t_tree *root, int data)
{
	if (!root)
		return (NULL);
	if (root->data > data)
		return (ft_search_tree_node(root->left, data));
	else if (root->data < data)
		return (ft_search_tree_node(root->right, data));
	else if (root->data == data)
		return (root);
	return (NULL);
}