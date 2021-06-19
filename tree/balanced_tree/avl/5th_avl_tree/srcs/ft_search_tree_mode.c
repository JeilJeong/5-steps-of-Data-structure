#include "../includes/ft_avl.h"

void	ft_search_tree_mode(t_tree *root)
{
	int		input;
	int		data;
	t_tree	*ret;

	input = 0;
	data = 0;
	ret = NULL;
	if (!root)
		return ;
	while (1)
	{
		ft_println(1);
		printf("+++[Search Mode]+++\n");
		printf("(1) Type Data\n");
		printf("(2) Return to Menu\n");
		printf(">>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("Type Data: ");
			scanf("%d", &data);
			ret = ft_search_tree_node(root, data);
			if (ret)
			{
				printf("[%d] == Exist\n", data);
				if (ret->parent)
					printf("[Parent] == %d\n", ret->parent->data);
				else
					printf("[Parent] == NULL\n");
				if (ret->left)
					printf("[Left] == %d\n", ret->left->data);
				else
					printf("[Left] == NULL\n");
				if (ret->right)
					printf("[Right] == %d\n", ret->right->data);
				else
					printf("[Right] == NULL\n");
			}
			else
				printf("[%d] == NULL\n", data);
		}
		else if (input == 2)
			break;
	}
}

t_tree	*ft_search_tree_node(t_tree *root, int data)
{
	t_tree	*ret;

	ret = NULL;
	if (!root)
		return (ret);
	if (root->data == data)
		ret = root;
	else if (root->data > data)
		ret = ft_search_tree_node(root->left, data);
	else if (root->data < data)
		ret = ft_search_tree_node(root->right, data);
	return (ret);
}