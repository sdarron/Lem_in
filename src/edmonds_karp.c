/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:56:25 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:56:28 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		can_go(t_map *map, int *visited, int prev, int tmp)
{
	if (visited[tmp] != -1)
		return (0);
	if (((map->visited_rooms[prev] == 0) ||
	(prev == 0)) && (map->edmonds_karp_solution[prev][tmp] == 0))
		return (1);
	if (map->visited_rooms[prev] == 1)
	{
		if ((map->visited_rooms[tmp] == 1) &&
		(map->edmonds_karp_solution[tmp][prev] == 1))
			return (1);
		if (map->visited_rooms[tmp] == 0)
		{
			if (map->visited_rooms[visited[prev]] == 1)
				return (1);
		}
	}
	return (0);
}

void	add_to_queue_edk(t_int *queue, t_int *tmp, int *visited, t_map *map)
{
	int		prev;

	prev = queue->data;
	while (queue->next)
		queue = queue->next;
	while (tmp)
	{
		if (can_go(map, visited, prev, tmp->data))
		{
			visited[tmp->data] = prev;
			queue->next = (t_int*)malloc(sizeof(t_int));
			if (!queue->next)
				exit_func(map, 0);
			queue->next->data = tmp->data;
			queue->next->next = NULL;
			queue = queue->next;
		}
		tmp = tmp->next;
	}
}

int		*bfs_edk(t_map *map)
{
	t_int	*queue;
	int		*visited;

	visited = init_visited_edk(map);
	queue = init_queue(map);
	while (queue)
	{
		if ((map->links_matrix[queue->data][1] == 1) &&
		(map->edmonds_karp_solution[queue->data][1] == 0))
		{
			visited[1] = queue->data;
			free_queue(queue);
			return (visited);
		}
		add_to_queue_edk(queue, map->links_list[queue->data], visited, map);
		queue = pop_first_from_queue(queue);
	}
	free(visited);
	free_queue(queue);
	return (NULL);
}

t_map	*add_path_edk(t_map *map, int *path)
{
	int		i;
	int		j;

	j = 0;
	while (j < map->number_of_rooms)
	{
		j++;
	}
	i = 1;
	while (i != 0)
	{
		if (map->edmonds_karp_solution[i][path[i]] == 1)
			map->edmonds_karp_solution[i][path[i]] = 0;
		else
			map->edmonds_karp_solution[path[i]][i] = 1;
		map->visited_rooms[path[i]] = 1;
		i = path[i];
	}
	free(path);
	return (map);
}

char	**edmonds_karp_solution(t_map *map)
{
	int		*path;
	int		i;

	map->edmonds_karp_solution = init_char_matrix(map, map->number_of_rooms);
	while ((path = bfs_edk(map)) != NULL)
	{
		map = add_path_edk(map, path);
	}
	i = 0;
	while (i < map->number_of_rooms)
	{
		if (map->edmonds_karp_solution[0][i] == 1)
			map->edk_number_of_paths += 1;
		i++;
	}
	return (map->edmonds_karp_solution);
}
