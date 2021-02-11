/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:08:03 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/17 17:08:05 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		*copy_int_array(const int *array, int size, t_map *map)
{
	int		i;
	int		*result;

	result = (int*)malloc(sizeof(int) * size);
	if (!result)
		exit_func(map, 0);
	i = 0;
	while (i < size)
	{
		result[i] = array[i];
		i++;
	}
	return (result);
}

int		*init_int_array(t_map *map, int size)
{
	int		*result;

	result = (int*)malloc(sizeof(int) * size);
	if (!result)
		exit_func(map, 0);
	return (result);
}

int		*init_int_array_with_zeros(t_map *map, int size)
{
	int		i;
	int		*result;

	result = (int*)malloc(sizeof(int) * size);
	if (!result)
		exit_func(map, 0);
	i = 0;
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}

int		**init_array(t_map *map)
{
	int		**result;

	result = (int**)malloc(sizeof(int*) * 2);
	if (!result)
		exit_func(map, 0);
	result[0] = NULL;
	result[1] = NULL;
	return (result);
}

int		**init_paths_array(int **sizes, int number_of_paths, t_map *map)
{
	int		**result;
	int		i;

	result = (int**)malloc(sizeof(int*) * number_of_paths);
	if (!result)
		exit_func(map, 0);
	i = 0;
	while (i < number_of_paths)
	{
		result[i] = (int*)malloc(sizeof(int) * sizes[0][i]);
		if (!result[i])
			exit_func(map, 0);
		i++;
	}
	return (result);
}
