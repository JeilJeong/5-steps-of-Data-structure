#include "../includes/ft_tree.h"

t_tree	*ft_create_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	ret->data = data;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}

int		ft_insert_node(t_tree **root, t_tree *node)
{
	if (*root == NULL)
	{
		*root = node;
		return (1);
	}
	else if ((*root)->data > node->data)
		return (ft_insert_node(&((*root)->left), node));
	else if ((*root)->data < node->data)
		return (ft_insert_node(&((*root)->right), node));
	return (0);
}

t_tree	*ft_delete_node(t_tree *root, int *count)
{
	int		input;
	printf("\n	delete number: ");
	scanf("%d", &input);
	return (ft_delete_input(root, input, count));
}

t_tree	*ft_delete_input(t_tree *root, int data, int *count)
{
	t_tree	*ret;

	if (root == NULL)
		return (NULL);
	else if (root->data > data)
		root->left = ft_delete_input(root->left, data, count);
	else if (root->data < data)
		root->right = ft_delete_input(root->right, data, count);
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			ft_print_delete_case(DEL_TERMINAL);
			free(root);
			*count -= 1;
			return (NULL);
		}
		else if (root->left && root->right)
		{
			ft_print_delete_case(DEL_BOTH);
			ret = ft_find_max_node(root->left);
			free(root);
			*count -= 1;
			return (ret);
		}
		else if (root->left)
		{
			ft_print_delete_case(DEL_LEFT);
			ret = root->left;
			free(root);
			*count -= 1;
			return (ret);
		}
		else if (root->right)
		{
			ft_print_delete_case(DEL_RIGHT);
			ret = root->right;
			free(root);
			*count -= 1;
			return (ret);
		}
	}
	return (root);
}

t_tree	*ft_delete_tree(t_tree *root)
{
	if (root == NULL)
		return (NULL);
	if (root->left)
		root->left = ft_delete_tree(root->left);
	if (root->right)
		root->right = ft_delete_tree(root->right);
	if (!(root->left) && !(root->right))
		free(root);
	return (NULL);
}