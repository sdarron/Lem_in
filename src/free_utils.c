/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:56:36 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:56:38 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_char_table(char **table, int size)
{
	int		i;

	if (!table)
		return ;
	i = 0;
	while (i < size)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_list(t_int **list, t_map *map)
{
	t_int	*tmp;
	int		i;

	i = 0;
	if (!list)
		return ;
	while (i < map->number_of_rooms)
	{
		while (list[i])
		{
			tmp = list[i];
			list[i] = list[i]->next;
			free(tmp);
		}
		i++;
	}
	free(list);
}

void	free_int_table(int **table, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_map(t_map *map)
{
	free_char_table(map->comments->table, map->comments->size);
	free(map->comments);
	free_char_table(map->room_lines->table, map->room_lines->size);
	free(map->room_lines);
	free_char_table(map->link_lines->table, map->link_lines->size);
	free(map->link_lines);
	free_char_table(map->room_names, map->number_of_rooms);
	free_char_table(map->links_matrix, map->number_of_rooms);
	free_list(map->links_list, map);
	free(map->visited_rooms);
	free_int_table(map->shortest_paths, map->number_of_paths);
	free_char_table(map->edmonds_karp_solution, map->number_of_rooms);
	free_int_table(map->result_paths, map->result_number_of_paths);
	free(map->edk_real_sizes);
	free(map);
}
