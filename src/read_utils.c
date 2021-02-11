/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:57:31 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:57:36 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		add_to_table(t_table *table, char *line)
{
	char	**tmp;
	int		i;

	tmp = (char**)malloc(sizeof(char*) * (table->size + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (i < table->size)
	{
		tmp[i] = table->table[i];
		i++;
	}
	tmp[i] = ft_strdup(line);
	free(table->table);
	table->table = tmp;
	table->size++;
	return (1);
}

char	*read_links(t_map *map, char *line)
{
	if (is_comment(line) || is_good_link(map, line))
	{
		if (!add_to_table(map->link_lines, line))
			exit_func(map, 0);
	}
	else
		exit_func(map, 1);
	free(line);
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (is_comment(line) || is_good_link(map, line))
		{
			if (!add_to_table(map->link_lines, line))
				exit_func(map, 0);
		}
		else
			return (line);
		free(line);
	}
	return (NULL);
}

char	*read_rooms(t_map *map)
{
	char	*line;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (is_comment(line) || is_good_room_name(line))
		{
			if (add_to_table(map->room_lines, line))
			{
				if (!is_comment(line))
					map->number_of_rooms++;
			}
			else
				exit_func(map, 0);
		}
		else
			return (line);
		free(line);
	}
	return (NULL);
}

void	read_map(t_map *map)
{
	char *line;

	while ((get_next_line(STDIN_FILENO, &line) > 0) && is_comment(line))
	{
		if (!add_to_table(map->comments, line))
			exit_func(map, 0);
	}
	if (!line)
		exit_func(map, 1);
	if (is_good_number_of_ants(line))
		map->number_of_ants = ft_atoi(line);
	else
		exit_func(map, 1);
	free(line);
	line = read_rooms(map);
	if (!check_rooms(map))
		exit_func(map, 1);
	if (!line)
		exit_func(map, 1);
	map = parse_room_names(map);
	line = read_links(map, line);
	free(line);
	map = parse_links(map);
}
