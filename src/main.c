/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:51:02 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:56:56 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include "../libft/includes/libft.h"

void	exit_func(t_map *map, int flag_error)
{
	if (flag_error)
	{
		ft_putstr("ERROR\n");
	}
	free_map(map);
	exit(1);
}

t_map	*init_map_part2(t_map *map)
{
	map->number_of_paths = 0;
	map->shortest_paths = NULL;
	map->visited_rooms = NULL;
	map->flag_simplest_path = 0;
	map->links_list = NULL;
	map->links_matrix = NULL;
	map->edmonds_karp_solution = NULL;
	map->edk_number_of_paths = 0;
	map->edk_real_sizes = NULL;
	map->result_paths = NULL;
	map->result_number_of_paths = 0;
	return (map);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (!map)
		exit(1);
	map->number_of_ants = 0;
	map->number_of_rooms = 0;
	map->room_names = NULL;
	map->room_lines = (t_table*)malloc(sizeof(t_table));
	map->link_lines = (t_table*)malloc(sizeof(t_table));
	map->comments = (t_table*)malloc(sizeof(t_table));
	if ((!map->room_lines) || (!map->link_lines) || (!map->comments))
		exit_func(map, 0);
	map->room_lines->table = NULL;
	map->link_lines->table = NULL;
	map->comments->table = NULL;
	map->comments->size = 0;
	map->room_lines->size = 0;
	map->link_lines->size = 0;
	return (init_map_part2(map));
}

t_map	*init_visited(t_map *map)
{
	int		i;

	map->visited_rooms = (int*)malloc(sizeof(int) * map->number_of_rooms);
	if (!map->visited_rooms)
		exit_func(map, 0);
	i = 0;
	while (i < map->number_of_rooms)
	{
		map->visited_rooms[i] = 0;
		i++;
	}
	return (map);
}

int		main(void)
{
	t_map	*map;
	int		k;

	map = init_map();
	read_map(map);
	map = init_visited(map);
	solution(map);
	k = 0;
	while (k < map->number_of_rooms)
	{
		map->visited_rooms[k] = 0;
		k++;
	}
	edmonds_karp_solution(map);
	choose_solution(map);
	free_map(map);
	return (0);
}
