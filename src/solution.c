/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:57:44 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:57:50 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*init_visited_array(t_map *map)
{
	int		*visited;
	int		i;

	visited = (int*)malloc(map->number_of_rooms * sizeof(int));
	if (!visited)
		exit_func(map, 0);
	i = 0;
	while (i < map->number_of_rooms)
	{
		if (map->visited_rooms[i] == 1)
			visited[i] = -2;
		else
			visited[i] = -1;
		i++;
	}
	return (visited);
}

int		*bfs(t_map *map)
{
	t_int	*queue;
	int		*visited;

	visited = init_visited_array(map);
	queue = init_queue(map);
	while (queue)
	{
		if (map->links_matrix[queue->data][1])
		{
			visited[1] = queue->data;
			free_queue(queue);
			return (visited);
		}
		add_to_queue(queue, map->links_list[queue->data], visited, map);
		queue = pop_first_from_queue(queue);
	}
	free(visited);
	free_queue(queue);
	return (NULL);
}

t_map	*add_path(t_map *map, int *path)
{
	int		**array;
	int		i;

	map->number_of_paths += 1;
	array = (int**)malloc(sizeof(int*) * map->number_of_paths);
	if (!array)
		exit_func(map, 0);
	i = 0;
	while (i < (map->number_of_paths - 1))
	{
		array[i] = map->shortest_paths[i];
		i++;
	}
	array[i] = path;
	free(map->shortest_paths);
	map->shortest_paths = array;
	i = 1;
	while (i != 0)
	{
		map->visited_rooms[path[i]] = 1;
		i = path[i];
	}
	return (map);
}

int		**solution(t_map *map)
{
	int		*path;

	while ((path = bfs(map)) != NULL)
	{
		map = add_path(map, path);
	}
	return (map->shortest_paths);
}
