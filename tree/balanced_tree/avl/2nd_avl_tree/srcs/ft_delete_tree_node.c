#include "../includes/ft_avl.h"

t_tree	*ft_delete_node(t_tree *root, int *count)
{
	int		input;
	t_tree	*ret;

	input = 0;
	ret = NULL;
	while (1)
	{
		printf("	*** DELETE NODE MODE ***\n");
		printf("	[1] TYPE NODE\n");
		printf("	[2] BACK TO MAIN\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("	Type data: ");
			scanf("%d", &input);
			ret = ft_delete_tree_node(root, root->parent, input);
			*count -= 1;
			ft_println(1);
		}
		else if (input == 2)
			return (ret);
	}
	return (root);
}

t_tree	*ft_delete_tree_node(t_tree *root, t_tree *parent, int data)
{
	t_tree	*max_node;
	t_tree	*ret;

	ret = NULL;
	if (!root)
		return (root);
	if (root->data > data)
		root->left = ft_delete_tree_node(root->left, root, data);
	else if (root->data < data)
		root->right = ft_delete_tree_node(root->right, root, data);
	else if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			printf("	[%d]: leaf node\n", root->data);
			free(root);
			return (NULL);
		}
		else if (root->left && !root->right)
		{
			printf("	[%d]: has left sub tree\n", root->data);
			ret = root->left;
			free(root);
			ret->parent = parent;
			ft_resolve_height(ret, ret->height - 1);
			return (ret);
		}
		else if (!root->left && root->right)
		{
			printf("	[%d]: has right sub tree\n", root->data);
			ret = root->right;
			free(root);
			ret->parent = parent;
			ft_resolve_height(ret, ret->height - 1);
			return (ret);
		}
		printf("	[%d]: has both left and right sub tree\n", root->data);
		max_node = ft_find_left_max(root->left);
		root->data = max_node->data;
		root->left = ft_delete_tree_node(root->left, root, max_node->data);
	}
	return (root);
}

void	ft_resolve_height(t_tree *root, int height)
{
	if (!root)
		return ;
	root->height = height;
	if (root->left)
		ft_resolve_height(root->left, height - 1);
	if (root->right)
		ft_resolve_height(root->right, height - 1);
}

t_tree	*ft_find_left_max(t_tree *root)
{
	if (!root)
		return (NULL);
	if (root->right)
		return (ft_find_left_max(root->right));
	return (root);
}