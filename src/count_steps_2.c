/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 14:09:38 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/19 14:09:40 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		count_path_size(int **paths, int i)
{
	int		size;
	int		j;

	size = 0;
	j = 1;
	while (j != 0)
	{
		j = paths[i][j];
		size++;
	}
	return (size);
}

int		*init_paths_sizes_from_int(int **paths, t_map *map, int *len)
{
	int		*result;
	int		i;
	int		k;

	*len = map->number_of_paths + map->flag_simplest_path;
	result = init_int_array(map, *len);
	k = 0;
	if (map->flag_simplest_path == 1)
	{
		k++;
		result[0] = 1;
	}
	i = 0;
	while (i < map->number_of_paths)
	{
		result[k] = count_path_size(paths, i);
		k++;
		i++;
	}
	return (result);
}
