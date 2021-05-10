#include "../includes/ft_avl.h"

int		main(void)
{
	int		i;
	int		data;
	int		size;
	int		range;
	int		count;
	int		input;
	t_tree	*root;
	t_tree	*node;
	t_tree	*tmp;

	count = 0;
	root = NULL;
	
	// Type size & range
	printf("size: ");
	scanf("%d", &size);
	printf("range: ");
	scanf("%d", &range);
	ft_println(1);

	// create node n times & insert node to tree
	i = -1;
	srand((unsigned int)time(NULL));
	while (++i < size)
	{
		data = rand() % range;
		node = ft_create_node(data);
		if ((tmp = ft_insert_node(&root, node, NULL, 0)))
		{
			write(1, "!!\n", 3);
			count += 1;
			if (tmp->parent == NULL)
			{
				root = tmp;
				write(1, "--\n", 3);
			}
			write(1, "??\n", 3);
		}
	}
	// i = -1;
	// srand((unsigned int)time(NULL));
	// while (++i < size)
	// {
	// 	data = rand() % range;
	// 	node = ft_create_node(data);
	// 	count += ft_insert_node(&root, node, NULL, 0);
	// }

	// menu
	while (1)
	{
		printf("[1] PRINT TREE [2] SEARCH NODE [3] DELETE NODE [4] DELETE TREE [5] EXIT\n");
		printf(">>> ");
		scanf("%d", &input);
		if (input == 1)
		{
			// check by print tree
			while (1)
			{
				printf("[1] PRE_ORDER [2] IN_ORDER [3] POST_ORDER [4] LEVEL [5] EXIT\n");
				printf(">>> ");
				scanf("%d", &input);
				if (input == 1)
				{
					printf("PRE_ORDER: ");
					if (ft_print_tree(root, PRE_ORDER) == ABNORMAL)
						return (ABNORMAL);
				}
				else if (input == 2)
				{
						printf("IN_ORDER: ");
						if (ft_print_tree(root, IN_ORDER) == ABNORMAL)
							return (ABNORMAL);
				}
				else if (input == 3)
				{
						printf("POST_ORDER: ");
						if (ft_print_tree(root, POST_ORDER) == ABNORMAL)
							return (ABNORMAL);
				}
				else if (input == 4)
				{
						printf("LEVEL: ");
						if (ft_print_tree(root, LEVEL) == ABNORMAL)
							return (ABNORMAL);
				}
				else if (input == 5)
					break;
				ft_println(1);
				printf("Node Count: %d\n", count);
				ft_println(2);
			}
		}
		else if (input == 2)
		{
			// search node in tree
			while (1)
			{
				printf("Type node to find(Type neg num if you want to exit)\n");
				printf(">>> ");
				scanf("%d", &input);
				if (input < 0)
					break;
				else
					ft_search_node(root, input);
				ft_println(1);
			}
		}
		else if (input == 3)
		{
			// delete node in tree
			while (1)
			{
				printf("Type node to remove(Type neg num if wanna exit)\n");
				printf(">>> ");
				scanf("%d", &input);
				if (input < 0)
					break;
				else
				{
					if ((root = ft_delete_node(root, input)))
						count -= 1;
				}
				ft_println(1);
			}
		}
		else if (input == 4)
		{
			root = ft_delete_tree(root);
			if (!root)
			{
				printf("The Tree has been deleted successfully\n");
				count = 0;
			}
			else
				printf("The Tree doesn't have been deleted\n");
		}
		else if (input == 5)
			return (NORMAL);
		else if (input == 6)
		{
			printf("find deepest height\n");
			printf("%d\n", ft_find_deepest_height(root));
			printf("%d\n", ft_find_deepest_height(root->left));
			printf("%d\n", ft_find_deepest_height(root->right));
		}
	}
}