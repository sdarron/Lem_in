/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_links_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:01:19 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/19 15:01:23 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*find_second_name(char *line)
{
	int		i;

	i = 0;
	while (line[i] && (line[i] != '-'))
		i++;
	if (!line[i])
		return (NULL);
	line[i] = '\0';
	return (&line[i + 1]);
}

char	**init_char_matrix(t_map *map, int size)
{
	char	**result;
	int		i;
	int		j;

	result = (char**)malloc(sizeof(char*) * size);
	if (!result)
		exit_func(map, 0);
	i = 0;
	while (i < size)
	{
		result[i] = (char*)malloc(sizeof(char) * size);
		if (!result[i])
			exit_func(map, 0);
		j = 0;
		while (j < size)
		{
			result[i][j] = 0;
			j++;
		}
		i++;
	}
	return (result);
}

t_int	**init_list_matrix(t_map *map, int size)
{
	t_int	**lists;
	int		i;

	i = 0;
	lists = (t_int**)malloc(sizeof(t_int*) * size);
	if (!lists)
		exit_func(map, 0);
	while (i < size)
	{
		lists[i] = NULL;
		i++;
	}
	return (lists);
}
