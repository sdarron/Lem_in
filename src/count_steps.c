/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:02:03 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/17 17:02:07 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		count_path_size_edk(char **matrix, int i)
{
	int		j;
	int		size;
	int		k;

	j = i;
	size = 1;
	while (j != 1)
	{
		k = 0;
		while (matrix[j][k] != 1)
			k++;
		size++;
		j = k;
	}
	return (size);
}

int		*init_paths_sizes_from_char(char **matrix, t_map *map, int *len)
{
	int		*result;
	int		i;
	int		l;

	*len = map->edk_number_of_paths + map->flag_simplest_path;
	result = init_int_array(map, *len);
	l = 0;
	if (map->flag_simplest_path == 1)
	{
		l++;
		result[0] = 1;
	}
	i = 0;
	while (i < map->number_of_rooms)
	{
		if (matrix[0][i] == 1)
		{
			result[l] = count_path_size_edk(matrix, i);
			l++;
		}
		i++;
	}
	map->edk_real_sizes = copy_int_array(result, *len, map);
	ft_quicksort(result, 0, *len - 1);
	return (result);
}

int		*init_simplest_path_size(t_map *map, int *len)
{
	int		*result;

	*len = 1;
	result = init_int_array(map, *len);
	result[0] = 1;
	return (result);
}

int		count_sizes(int **sizes, int size, int number_of_ants)
{
	int		i;
	int		max;

	max = -1;
	while (number_of_ants > 0)
	{
		i = 0;
		while (((i + 1) < size) &&
		((sizes[0][i] + sizes[1][i]) >= (sizes[0][i + 1] + sizes[1][i + 1])))
			i++;
		sizes[1][i] += 1;
		if (max < sizes[0][i] + sizes[1][i])
			max = sizes[0][i] + sizes[1][i];
		number_of_ants--;
	}
	return (max - 1);
}

int		count_steps(int **paths, char **matrix, t_map *map, int **sizes)
{
	int		size;

	size = 0;
	if (paths)
		sizes[0] = init_paths_sizes_from_int(paths, map, &size);
	else if (matrix)
		sizes[0] = init_paths_sizes_from_char(matrix, map, &size);
	else if (map->flag_simplest_path == 1)
		sizes[0] = init_simplest_path_size(map, &size);
	else
		exit_func(map, 1);
	sizes[1] = init_int_array_with_zeros(map, size);
	return (count_sizes(sizes, size, map->number_of_ants));
}
