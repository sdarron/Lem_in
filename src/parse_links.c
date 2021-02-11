/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:57:05 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:57:06 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		find_in_room_names(t_map *map, char *line)
{
	int		i;

	i = 0;
	while (i < map->number_of_rooms)
	{
		if (!ft_strcmp(map->room_names[i], line))
			return (i);
		i++;
	}
	exit_func(map, 1);
	return (0);
}

void	parse_nums_from_link(char *line, int *a, int *b, t_map *map)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strdup(line);
	tmp1 = find_second_name(tmp);
	*a = find_in_room_names(map, tmp);
	*b = find_in_room_names(map, tmp1);
	free(tmp);
}

t_map	*add_to_link_list(t_map *map, int a, int b)
{
	t_int	*tmp;

	if (!map->links_list[a])
	{
		map->links_list[a] = (t_int*)malloc(sizeof(t_int));
		if (!map->links_list[a])
			exit_func(map, 0);
		map->links_list[a]->data = b;
		map->links_list[a]->next = NULL;
	}
	else
	{
		tmp = map->links_list[a];
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = (t_int*)malloc(sizeof(t_int));
		if (!tmp->next)
			exit_func(map, 0);
		tmp->next->data = b;
		tmp->next->next = NULL;
	}
	return (map);
}

int		is_simplest_way(int a, int b)
{
	if (((a == 1) && (b == 0)) || ((a == 0) && (b == 1)))
		return (1);
	return (0);
}

t_map	*parse_links(t_map *map)
{
	int		i;
	int		num[2];

	map->links_matrix = init_char_matrix(map, map->number_of_rooms);
	map->links_list = init_list_matrix(map, map->number_of_rooms);
	i = 0;
	while (i < map->link_lines->size)
	{
		if (!is_comment(map->link_lines->table[i]))
		{
			parse_nums_from_link(map->link_lines->table[i],
						&num[0], &num[1], map);
			if (is_simplest_way(num[0], num[1]))
				map->flag_simplest_path = 1;
			else
			{
				map->links_matrix[num[0]][num[1]] = 1;
				map->links_matrix[num[1]][num[0]] = 1;
				map = add_to_link_list(map, num[0], num[1]);
				map = add_to_link_list(map, num[1], num[0]);
			}
		}
		i++;
	}
	return (map);
}
