/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:57:13 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:57:17 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*cut_first(char *line)
{
	char	*result;
	int		i;

	i = 0;
	while (line[i] && (line[i] != ' '))
		i++;
	result = (char*)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i] = '\0';
	while (i > 0)
	{
		result[i - 1] = line[i - 1];
		i--;
	}
	return (result);
}

void	skip_comments(int *i, t_map *map)
{
	(*i)++;
	while (is_comment(map->room_lines->table[(*i)]))
		(*i)++;
}

t_map	*parse_room_names(t_map *map)
{
	int		i;
	int		k;

	map->room_names = (char**)malloc(sizeof(char*) * map->number_of_rooms);
	if (!map->room_names)
		exit_func(map, 0);
	i = 0;
	k = 2;
	while (i < map->room_lines->size)
	{
		if (!ft_strcmp(map->room_lines->table[i], "##start"))
		{
			skip_comments(&i, map);
			map->room_names[0] = cut_first(map->room_lines->table[i]);
		}
		else if (!ft_strcmp(map->room_lines->table[i], "##end"))
		{
			skip_comments(&i, map);
			map->room_names[1] = cut_first(map->room_lines->table[i]);
		}
		else if (!is_comment(map->room_lines->table[i]))
			map->room_names[k++] = cut_first(map->room_lines->table[i]);
		i++;
	}
	return (map);
}
