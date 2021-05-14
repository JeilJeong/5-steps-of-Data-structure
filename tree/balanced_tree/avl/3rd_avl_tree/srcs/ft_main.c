#include "../includes/ft_avl.h"

int		main(void)
{
	int		i;
	int		size;
	int		range;
	int		data;
	int		input;
	int		count;
	t_tree	*root;
	t_tree	*node;

	// initialization
	data = 0;
	count = 0;
	root = NULL;
	while (1)
	{
		input = 0;
		ft_println(1);
		printf("	[1] RANDOM  TEST\n");
		printf("	[2] EXIT PROGRAM\n");
		printf("	>>> ");
		scanf("%d", &input);
		ft_println(1);
		if (input == 1)
		{
			printf("	SIZE: ");
			scanf("%d", &size);
			printf("	RANGE: ");
			scanf("%d", &range);
			if (size < 0 || range < 0)
				continue;
			i = -1;
			srand((unsigned int)time(NULL));
			while (++i < size)
			{
				data = rand() % range;
				while (!(node = ft_create_tree_node(data)))
					printf("alloc error: ft_create_tree_node called by ft_main\n");
				ft_insert_tree_node(&root, &root, node, NULL, 0);
			}
		}
		else if (input == 2)
		{

		}
	}

}