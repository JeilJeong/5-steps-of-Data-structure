#include "../includes/ft_tree.h"

extern int	count;

t_tree	*ft_new_node(int data)
{
	t_tree	*ret;

	if (!(ret = (t_tree *)malloc(sizeof(t_tree))))
	{
		printf("malloc error: ft_new_node\n");
		return (NULL);
	}
	ret->data = data;
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}

int		ft_insert_node(t_tree **root, int data)
{
	if (*root == NULL)
	{
		*root = ft_new_node(data);
		return (1);
	}
	else if ((*root)->data > data)
		return (ft_insert_node(&((*root)->left), data));
	else if ((*root)->data < data)
		return (ft_insert_node(&((*root)->right), data));
	return (0);
}

void	ft_print_node(t_tree *root, int	order)
{
	if (root == NULL)
		return ;
	else if (order == PRE_ORDER)
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

void	ft_search_node(t_tree *root, int search)
{
	if (root == NULL)
	{
		printf("[%d] doesn't exist in tree\n", search);
		return ;
	}
	else if (root->data == search)
	{
		printf("[%d] exists in tree\n", search);
		return ;
	}
	else if (root->data > search)
		ft_search_node(root->left, search);
	else if (root->data < search)
		ft_search_node(root->right, search);
}

t_tree	*ft_delete_node(t_tree *root, int data)
{
	t_tree	*ret;

	if (root == NULL)
		return (NULL);
	else if (root->data > data)
		root->left = ft_delete_node(root->left, data);
	else if (root->data < data)
		root->right = ft_delete_node(root->right, data);
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			printf("\ndeleted case: [%d] node is terminal node\n", data);
			free(root);
			count -= 1;
			return (NULL);
		}
		else if (root->left && root->right)
		{
			printf("\ndeleted case: [%d] node have both left and right subtrees\n", data);
			ret = ft_max_node(root->left);
			free(root);
			count -= 1;
			return (ret);
		}
		else if (root->left)
		{
			printf("\ndeleted case: [%d] node has left subtree\n", data);
			ret = root->left;
			free(root);
			count -= 1;
			return (ret);
		}
		else if (root->right)
		{
			printf("\ndeleted case: [%d] node has right subtree\n", data);
			ret = root->right;
			free(root);
			count -= 1;
			return (ret);
		}
	}
	return (root);
}

t_tree	*ft_max_node(t_tree *root)
{
	if (root->right == NULL)
	{
		return (root);
	}
	return (ft_max_node(root->right));
}