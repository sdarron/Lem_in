/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:39:02 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/19 14:39:03 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*init_visited_edk(t_map *map)
{
	int		*visited;
	int		i;

	visited = (int*)malloc(map->number_of_rooms * sizeof(int));
	if (!visited)
		exit_func(map, 0);
	i = 1;
	visited[0] = 1;
	while (i < map->number_of_rooms)
	{
		visited[i] = -1;
		i++;
	}
	return (visited);
}
