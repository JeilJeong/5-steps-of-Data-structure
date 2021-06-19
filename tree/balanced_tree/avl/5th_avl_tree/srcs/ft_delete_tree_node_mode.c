#include "../includes/ft_avl.h"

void		ft_delete_tree_node_mode(t_tree **og_root, int *count)
{
	int			input;
	int			data;
	t_retNode	*ret_node;

	input = 0;
	data = 0;
	if (!(*og_root))
		return ;
	while (1)
	{
		ft_println(1);
		printf("+++[Delete Mode]+++\n");
		printf("(1) Type Data\n");
		printf("(2) Return to Menu\n");
		printf(">>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("Type Data: ");
			scanf("%d", &data);
			if (*og_root)
				ret_node = ft_delete_tree_node(og_root, *og_root, data, (*og_root)->parent, count);
			if (ret_node)
				ft_deletion_balancing_mode(og_root, ret_node);
			ft_println(1);
			printf("Level Trav: ");
			ft_level_trav_tree(*og_root);
			ft_println(1);
			printf("Count: %d\n", *count);
			free(ret_node);
			ret_node = NULL;
		}
		else if (input == 2)
			break;
	}
}

t_retNode	*ft_delete_tree_node(t_tree **og_root, t_tree *root, int data, t_tree *parent, int *count)
{
	t_retNode	*ret_node;
	t_tree		*max_node;

	ret_node = NULL;
	max_node = NULL;
	if (!(*og_root) || !root)
		return (NULL);
	if (root->data > data)
	{
		ret_node = ft_delete_tree_node(og_root, root->left, data, root, count);
		if (ret_node)
		{
			root->left = ret_node->child;
			ret_node->child = root;
		}
	}
	else if (root->data < data)
	{
		ret_node = ft_delete_tree_node(og_root, root->right, data, root, count);
		if (ret_node)
		{
			root->right = ret_node->child;
			ret_node->child = root;
		}
	}
	else if (root->data == data)
	{
		if (root->left && root->right)
		{
			if ((max_node = ft_max_val_in_left(root->left)))
			{
				printf("Case: %d has both left and right subtree\n", data);
				root->data = max_node->data;
				ret_node = ft_delete_tree_node(og_root, root->left, max_node->data, root, count);
				if (ret_node)
				{
					root->left = ret_node->child;
					ret_node->child = root;
				}
				return (ret_node);
			}
		}
		else
		{
			while (!(ret_node = ft_create_ret_node()))
				printf("alloc error: ft_create_ret_node << ft_delete_tree_node\n");
			if (!(root->left) && !(root->right))
			{
				printf("Case: %d is terminal node\n", data);
				if (!parent)
					*og_root = NULL;
				ret_node->child = NULL;
				ret_node->ret_bal = parent;
				free(root);
				*count -= 1;
				return (ret_node);
			}
			else if (root->left && !(root->right))
			{
				printf("Case: %d has left subtree\n", data);
				root->left->parent = parent;
				if (!parent)
					*og_root = root->left;
				ret_node->child = root->left;
				ret_node->ret_bal = parent;
				free(root);
				*count -= 1;
				return (ret_node);
			}
			else if (!(root->left) && root->right)
			{
				printf("Case: %d has right subtree\n", data);
				root->right->parent = parent;
				if (!parent)
					*og_root = root->right;
				ret_node->child = root->right;
				ret_node->ret_bal = parent;
				free(root);
				*count -= 1;
				return (ret_node);
			}
		}
	}
	return (ret_node);
}

t_tree		*ft_max_val_in_left(t_tree *root)
{
	t_tree	*ret;

	ret = root;
	if (!root)
		return (ret);
	if (root->right)
		ret = ft_max_val_in_left(root->right);
	return (ret);
}

t_retNode	*ft_create_ret_node(void)
{
	t_retNode	*ret;

	while (!(ret = (t_retNode *)malloc(sizeof(t_retNode))))
		printf("malloc error: ft_create_ret_node\n");
	ret->child = NULL;
	ret->ret_bal = NULL;
	return (ret);
}