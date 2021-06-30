#include "../includes/ft_graph.h"

void	ft_dfs_all(t_graph *graph)
{
	int		i;
	int		*visit;
	t_time	*visit_time;

	if (!graph)
		return ;
	if (!(visit_time = (t_time *)malloc(sizeof(t_time))))
	{
		printf("	malloc error: visit_time << ft_dfs_all\n");
		return ;
	}
	if (!(visit_time->pre = (int *)calloc(graph->used_vertex, sizeof(int))))
	{
		printf("	calloc error: visit_time->pre << ft_dfs_all\n");
		free(visit_time);
		visit_time = NULL;
		return ;
	}
	if (!(visit_time->post = (int *)calloc(graph->used_vertex, sizeof(int))))
	{
		printf("	calloc error: visit_time->post << ft_dfs_all\n");
		free(visit_time->pre);
		visit_time->pre = NULL;
		free(visit_time); 	
		visit_time = NULL;
		return ;
	}
	if (!(visit = (int *)calloc(graph->used_vertex, sizeof(int))))
	{
		printf("	calloc error: visit << ft_dfs_all\n");
		free(visit_time->pre);
		visit_time->pre = NULL;
		free(visit_time->post);
		visit_time->post = NULL;
		free(visit_time);
		visit_time = NULL;
		return ;
	}
	i = -1;
	ft_println(1);
	printf("	DFS: ");
	while (++i < graph->used_vertex)
	{
		if (!visit[i])
			ft_dfs(graph, i, visit, visit_time, 0);
	}
	ft_println(1);
}

void	ft_dfs(t_graph *graph, int index, int *visit, t_time *visit_time, int cnt)
{
	int		i;

	if (!graph ||index > graph->used_vertex || index < 0 || !visit || !visit_time)
		return ;
	visit_time->pre[index] = ++cnt;
	visit[index] = 1;
	printf("%d ", index);
	i = -1;
	while (++i < graph->used_vertex)
	{
		if (!visit[i] && graph->adj_graph[index][i])
			ft_dfs(graph, i, visit, visit_time, cnt);
	}
	visit_time->post[index] = ++cnt;
}