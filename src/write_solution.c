/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:23:40 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/19 15:23:44 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	write_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->comments->size)
	{
		ft_putendl(map->comments->table[i]);
		i++;
	}
	ft_putnbr(map->number_of_ants);
	ft_putchar('\n');
	i = 0;
	while (i < map->room_lines->size)
	{
		ft_putendl(map->room_lines->table[i]);
		i++;
	}
	i = 0;
	while (i < map->link_lines->size)
	{
		ft_putendl(map->link_lines->table[i]);
		i++;
	}
	ft_putchar('\n');
}

void	write_move(int number_of_ant, char *room_name)
{
	ft_putchar('L');
	ft_putnbr(number_of_ant);
	ft_putchar('-');
	ft_putstr(room_name);
	ft_putchar(' ');
}

char	*get_room_name(t_map *map, int i, int j)
{
	return (map->room_names[map->result_paths[i][j]]);
}

void	move_ants(int **queues, int **sizes, int *left_ants, t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->result_number_of_paths)
	{
		j = sizes[0][i] - 1;
		while (j > 0)
		{
			queues[i][j] = queues[i][j - 1];
			if (queues[i][j - 1] != 0)
				write_move(queues[i][j], get_room_name(map, i, j));
			j--;
		}
		if (sizes[1][i] > 0)
		{
			queues[i][0] = map->number_of_ants - (*left_ants) + 1;
			write_move(queues[i][0], get_room_name(map, i, 0));
			(*left_ants)--;
			sizes[1][i]--;
		}
		else
			queues[i][0] = 0;
		i++;
	}
}

void	write_solution(t_map *map, int **sizes, int steps)
{
	int		**queues;
	int		left_ants;

	write_map(map);
	queues = init_queues(map, sizes[0]);
	left_ants = map->number_of_ants;
	if (map->number_of_ants == 0)
		ft_putstr("No ants:)\n");
	while (steps > 0)
	{
		move_ants(queues, sizes, &left_ants, map);
		ft_putchar('\n');
		steps--;
	}
	free_int_table(sizes, 2);
	free_int_table(queues, map->result_number_of_paths);
}
