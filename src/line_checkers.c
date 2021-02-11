/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:56:46 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:56:48 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_comment(char *line)
{
	if (line && (line[0] == '#'))
		return (1);
	return (0);
}

int		is_num(char *line)
{
	unsigned int	i;

	i = 0;
	if (!line[0])
		return (0);
	i = line[0] == '+' ? 1 : 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int		is_good_link(t_map *map, char *line)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strdup(line);
	tmp1 = find_second_name(tmp);
	if (!tmp1)
	{
		free(tmp);
		return (0);
	}
	find_in_room_names(map, tmp);
	find_in_room_names(map, tmp1);
	free(tmp);
	return (1);
}

int		is_good_number_of_ants(char *line)
{
	long long int		num;

	num = ft_atoi(line);
	if (num != (long long int)(int)num)
		return (0);
	if (!is_num(line) || (num < 0))
		return (0);
	return (1);
}

int		is_good_room_name(char *line)
{
	int		i;

	if (!line)
		return (0);
	i = 0;
	if (line[0] && ((line[0] == 'L') || (line[0] == '#')))
		return (0);
	while (line[i] && (line[i] != ' '))
		i++;
	if (!line[i])
		return (0);
	if (!line[i + 1] || !ft_isdigit(line[i + 1]) || (i == 0))
		return (0);
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (!line[i] || (line[i] != ' '))
		return (0);
	if (!line[i + 1] || !ft_isdigit(line[++i]))
		return (0);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}
