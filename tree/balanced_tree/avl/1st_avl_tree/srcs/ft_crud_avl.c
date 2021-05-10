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

t_tree	*ft_insert_node(t_tree **root, t_tree *node, t_tree *parent, int height)
{
	write(1, "2!!\n", 4);
	if (!node)
		return (NULL);
	if (!(*root))
	{
		node->parent = parent;
		node->height = height;
		*root = node;
		return (ft_check_insert_balance(*root));
	}
	else if ((*root)->data >= node->data)
		return (ft_insert_node(&((*root)->left), node, *root, height + 1));
	else if ((*root)->data < node->data)
		return (ft_insert_node(&((*root)->right), node, *root, height + 1));
	return (NULL);
}

// int		ft_insert_node(t_tree **root, t_tree *node, t_tree *parent, int height)
// {
// 	if (!node)
// 		return (0);
// 	if (!(*root))
// 	{
// 		node->parent = parent;
// 		node->height = height;
// 		*root = node;
// 		return (1);
// 	}
// 	else if ((*root)->data >= node->data)
// 		return (ft_insert_node(&((*root)->left), node, *root, height + 1));
// 	else if ((*root)->data < node->data)
// 		return (ft_insert_node(&((*root)->right), node, *root, height + 1));
// 	return (0);
// }

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
	{
		if (root->height != 0)
			printf("%d exists in tree: height[%d], parent_data[%d], parent_heigth[%d]\n", \
			input, root->height, root->parent->data, root->parent->height);
		else
			printf("%d exists in tree: height[%d]\n", input, root->height);
	}
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
			tmp->parent = root->parent;
			free(root);
			ft_resolve_height(tmp);
			return (tmp);
		}
		else if (root->right && !root->left)
		{
			ft_print_delete_case(3);
			tmp = root->right;
			tmp->parent = root->parent;
			free(root);
			ft_resolve_height(tmp);
			return (tmp);
		}
		ft_print_delete_case(4);
		max_node = ft_find_max(root->left);
		root->data = max_node->data;
		root->left = ft_delete_node(root->left, max_node->data);
	}
	return (root);
}

t_tree	*ft_delete_tree(t_tree *root)
{
	if (!root)
		return (NULL);
	if (root->left)
		root->left = ft_delete_tree(root->left);
	if (root->right)
		root->right = ft_delete_tree(root->right);
	if (!root->left && !root->right)
	{
		free(root);
		return (NULL);
	}
	return (root);
}