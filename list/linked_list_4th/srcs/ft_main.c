#include "../includes/ft_list.h"

int		count = 0;

int		main(void)
{
	clock_t	start;
	clock_t	end;
	t_list	*head;
	int		i;
	int		pos;
	int		data;

	i = 0;
	head = ft_create_list();
	srand((unsigned int)time(NULL));
	while (i < 100)
	{
		pos = rand() % 3;
		data = rand() % 100;
		count += ft_insert_node(head, pos, data);
		i++;
	}
	ft_print_list(head);
	start = clock();
	ft_bubble_sort(head);
	end = clock();
	printf("\n**********bubble sort**********\n");
	ft_print_list(head);
	printf("time = %f\n", (float)(end - start)/CLOCKS_PER_SEC);
}