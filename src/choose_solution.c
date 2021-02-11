/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:26:07 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/17 19:26:09 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	reform_paths_from_int(t_map *map, int **sizes)
{
	int		i;
	int		k;
	int		j;

	map->result_paths = init_paths_array(sizes, map->number_of_paths +
	map->flag_simplest_path, map);
	i = 0;
	if (map->flag_simplest_path == 1)
	{
		map->result_paths[0][0] = 1;
		i++;
	}
	while (i < (map->number_of_paths + map->flag_simplest_path))
	{
		k = sizes[0][i] - 1;
		j = 1;
		while (j != 0)
		{
			map->result_paths[i][k--] = j;
			j = map->shortest_paths[i - map->flag_simplest_path][j];
		}
		i++;
	}
	map->result_number_of_paths = map->number_of_paths
			+ map->flag_simplest_path;
}

void	add_path_from_char(t_map *map, int i, int k)
{
	int		j;
	int		n;
	int		l;

	map->result_paths[i][0] = k;
	j = k;
	n = 1;
	while (j != 1)
	{
		l = 0;
		while (map->edmonds_karp_solution[j][l] != 1)
			l++;
		map->result_paths[i][n] = l;
		n++;
		j = l;
	}
}

int		*init_array_to_sorted_size(t_map *map, const int *sizes)
{
	int		*result;
	int		*flags;
	int		i;
	int		j;

	result = init_int_array(map, map->edk_number_of_paths
	+ map->flag_simplest_path);
	flags = init_int_array_with_zeros(map, map->edk_number_of_paths
	+ map->flag_simplest_path);
	i = 0;
	while (i < (map->edk_number_of_paths + map->flag_simplest_path))
	{
		j = 0;
		while (j < (map->edk_number_of_paths + map->flag_simplest_path))
		{
			if ((map->edk_real_sizes[i] == sizes[j]) && (flags[j] == 0))
				break ;
			j++;
		}
		result[i] = j;
		flags[j] = 1;
		i++;
	}
	free(flags);
	return (result);
}

void	reform_paths_from_char(t_map *map, int **sizes)
{
	int		i;
	int		k;
	int		*to_sorted_size;

	map->result_paths = init_paths_array(sizes, map->edk_number_of_paths, map);
	i = 0;
	if (map->flag_simplest_path == 1)
	{
		map->result_paths[0][0] = 1;
		i++;
	}
	to_sorted_size = init_array_to_sorted_size(map, sizes[0]);
	k = 0;
	while (k < map->number_of_rooms)
	{
		if (map->edmonds_karp_solution[0][k] == 1)
		{
			add_path_from_char(map, to_sorted_size[i], k);
			i++;
		}
		k++;
	}
	free(to_sorted_size);
	map->result_number_of_paths = map->edk_number_of_paths
			+ map->flag_simplest_path;
}

void	choose_solution(t_map *map)
{
	int		**sizes_first;
	int		**sizes_second;
	int		first;
	int		second;

	sizes_first = init_array(map);
	sizes_second = init_array(map);
	if ((first = count_steps(map->shortest_paths, NULL, map, sizes_first)) <=
	(second = count_steps(NULL, map->edmonds_karp_solution, map, sizes_second)))
	{
		free_int_table(sizes_second, 2);
		reform_paths_from_int(map, sizes_first);
	}
	else
	{
		free_int_table(sizes_first, 2);
		sizes_first = sizes_second;
		first = second;
		reform_paths_from_char(map, sizes_second);
	}
	write_solution(map, sizes_first, first);
}
