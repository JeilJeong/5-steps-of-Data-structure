#include "../includes/ft_avl.h"

t_tree	*ft_create_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
	{
		printf("malloc error: ft_create_node");
		ft_println(1);
		return (NULL);
	}
	ret->data = data;
	ret->height = 0;
	ret->left = NULL;
	ret->right = NULL;
	ret->parent = NULL;
	return (ret);
}

int		ft_insert_node(t_tree **root, t_tree *node)
{
	if (!node)
		return (0);
	if (!(*root))
	{
		*root = node;
		return (1);
	}
	else if ((*root)->data >= node->data)
		return (ft_insert_node(&((*root)->left), node));
	else if ((*root)->data < node->data)
		return (ft_insert_node(&((*root)->right), node));
	return (0);
}

void	ft_search_node(t_tree *root, int input)
{
	if (!root)
	{
		printf("%d does not exist in tree\n", input);
		return ;
	}
	else if (root->data > input)
		ft_search_node(root->left, input);
	else if (root->data < input)
		ft_search_node(root->right, input);
	else if (root->data == input)
		printf("%d exists in tree\n", input);
}

t_tree	*ft_delete_node(t_tree *root, int input)
{
	t_tree	*tmp;
	t_tree	*max_node;

	if (!root)
		return (NULL);
	if (root->data > input)
		root->left = ft_delete_node(root->left, input);
	else if (root->data < input)
		root->right = ft_delete_node(root->right, input);
	else if (root->data == input)
	{
		if (!root->left && !root->right)
		{
			ft_print_delete_case(1);
			free(root);
			return (NULL);
		}
		else if (root->left && !root->right)
		{
			ft_print_delete_case(2);
			tmp = root->left;
			free(root);
			return (tmp);
		}
		else if (root->right && !root->left)
		{
			ft_print_delete_case(3);
			tmp = root->right;
			free(root);
			return (tmp);
		}
		ft_print_delete_case(4);
		max_node = ft_find_max(root->left);
		root->data = max_node->data;
		root->left = ft_delete_node(root->left, max_node->data);
	}
	return (root);
}