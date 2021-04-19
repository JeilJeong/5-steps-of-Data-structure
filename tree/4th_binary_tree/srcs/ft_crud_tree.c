#include "../includes/ft_tree.h"

t_tree	*ft_create_tree_node(const int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree	*)malloc(sizeof(t_tree))))
	{
		printf("malloc error: ft_create_tree_node\n");
		return (ret);
	}
	ret->data = data;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}

void	ft_insert_tree_node(t_tree **root, t_tree *tree_node, int *count)
{
	if ((*root) == NULL)
	{
		*root = tree_node;
		*count += 1;
		return ;
	}
	else if ((*root)->data > tree_node->data)
		ft_insert_tree_node(&((*root)->left), tree_node, count);
	else if ((*root)->data < tree_node->data)
		ft_insert_tree_node(&((*root)->right), tree_node, count);
	else if ((*root)->data == tree_node->data)
		free(tree_node);
}

t_tree	*ft_delete_tree_node(t_tree *root, int data, int *count)
{
	t_tree	*ret;

	ret = NULL;
	if (!root)
		return(ret);
	else if (root->data > data)
		root->left = ft_delete_tree_node(root->left, data, count);
	else if (root->data < data)
		root->right = ft_delete_tree_node(root->right, data, count);
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			printf("Node is Terminal");
			free(root);
			*count -= 1;
			return (NULL);
		}
		else if (root->left && !root->right)
		{
			printf("Node has left sub-tree");
			ret = root->left;
			free(root);
			*count -= 1;
			return (ret);
		}
		else if (!root->left && root->right)
		{
			printf("Node has right sub-tree");
			ret = root->right;
			free(root);
			*count -= 1;
			return (ret);
		}
		else if (root->left && root->right)
		{
			printf("Node have both left and right sub-trees	");
			ret = ft_search_max_node(root->left);
			root->data = ret->data;
			root->left = ft_delete_tree_node(root->left, ret->data, count);
		}
	}
	return (root);
}

t_tree	*ft_delete_tree(t_tree *root, int *count)
{
	if (root == NULL)
		return (NULL);
	if (root->left)
		root->left = ft_delete_tree(root->left, count);
	if (root->right)
		root->right = ft_delete_tree(root->right, count);
	if (!root->left && !root->right)
	{
		free(root);
		*count -= 1;
	}
	return (NULL);
}