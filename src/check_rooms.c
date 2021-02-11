/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:56:13 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:56:18 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		check_s_e_room(int *i, int *flag, t_table *lines)
{
	if ((*flag) == 1)
		return (0);
	while ((((*i) + 1) < lines->size) &&
	(is_comment(lines->table[(*i) + 1])))
		(*i)++;
	if (((*i) + 1) < lines->size)
	{
		(*i)++;
		*flag = 1;
		return (1);
	}
	else
		return (0);
}

int		check_rooms(t_map *map)
{
	int		flag_start;
	int		flag_end;
	int		i;

	flag_start = 0;
	flag_end = 0;
	i = 0;
	while (i < map->room_lines->size)
	{
		if (!ft_strcmp(map->room_lines->table[i], "##start"))
		{
			if (!check_s_e_room(&i, &flag_start, map->room_lines))
				return (0);
		}
		else if (!ft_strcmp(map->room_lines->table[i], "##end"))
		{
			if (!check_s_e_room(&i, &flag_end, map->room_lines))
				return (0);
		}
		i++;
	}
	if ((flag_start == 1) && (flag_end == 1))
		return (1);
	return (0);
}
