#include "../includes/ft_tree.h"

void	ft_search_node(t_tree *root)
{
	int 	input;

	printf("\n	search number: ");
	scanf("%d", &input);
	ft_search_input(root, input);
}

void	ft_search_input(t_tree *root, int data)
{
	if (root == NULL)
		printf("	>>>[%d] doesn't exists in tree\n", data);
	else if (root->data == data)
		printf("	>>>[%d] exists in tree\n", data);
	else if (root->data > data)
		ft_search_input(root->left, data);
	else if (root->data < data)
		ft_search_input(root->right, data);
}

t_tree	*ft_find_max_node(t_tree *root)
{
	if (root->right == NULL)
		return (root);
	return (ft_find_max_node(root->right));
}