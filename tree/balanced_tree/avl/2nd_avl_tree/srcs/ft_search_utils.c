#include "../includes/ft_avl.h"

t_tree	*ft_search_node(t_tree *root)
{
	int		input;
	t_tree	*ret;

	ret = NULL;
	while (1)
	{
		input = 0;
		printf("	*** SEARCH MODE ***\n");
		printf("	[1] TYPE DATA\n");
		printf("	[2] BACK TO MAIN\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("	Type data: ");
			scanf("%d", &input);
			ret = ft_search_tree_node(root, input);
		}
		else if (input == 2)
			return (ret);
	}
	return (ret);
}

t_tree	*ft_search_tree_node(t_tree *root, int input)
{
	if (!root)
	{
		ft_println(1);
		printf("	[%d] does not exist in tree\n", input);
		ft_println(1);
		return (NULL);
	}
	if (root->data == input)
	{
		ft_println(1);
		printf("	Data:		%d\n", root->data);
		printf("	Height:		%d\n", root->height);
		if (root->parent)
		{
			printf("	Parent:		%d\n", root->parent->data);
			printf("	Parent Height:	%d\n", root->parent->height);
		}
		if (root->left)
		{
			printf("	Left:		%d\n", root->left->data);
			printf("	Left Height:	%d\n", root->left->height);
		}
		if (root->right)
		{
			printf("	Right:		%d\n", root->right->data);
			printf("	Right Height:	%d\n", root->right->height);
		}
		ft_println(1);
		return (root);
	}
	else if (root->data > input)
		return (ft_search_tree_node(root->left, input));
	else if (root->data < input)
		return (ft_search_tree_node(root->right, input));
	return (root);
}