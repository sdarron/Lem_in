/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_queues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:36:58 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/19 15:37:01 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		**init_queues(t_map *map, int *sizes)
{
	int		**queues;
	int		i;
	int		j;

	queues = (int**)malloc(sizeof(int*) * map->result_number_of_paths);
	if (!queues)
		exit_func(map, 0);
	i = 0;
	while (i < map->result_number_of_paths)
	{
		queues[i] = (int*)malloc(sizeof(int) * sizes[i]);
		if (!queues[i])
			exit_func(map, 0);
		j = 0;
		while (j < sizes[i])
		{
			queues[i][j] = 0;
			j++;
		}
		i++;
	}
	return (queues);
}
