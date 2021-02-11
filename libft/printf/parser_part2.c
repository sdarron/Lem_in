/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_format *form)
{
	form->flags = FLG_NONE;
	form->is_width = 0;
	form->width = 0;
	form->is_precision = 0;
	form->precision = 0;
	form->size = SIZE_NONE;
	form->char_zero = 0;
}

int		is_there_any_flag(const int i, const char *line)
{
	if ((line[i] == ' ') || (line[i] == '-') || (line[i] == '+')
		|| (line[i] == '0') || (line[i] == '#'))
		return (1);
	return (0);
}

void	add_flag(char c, t_format *res)
{
	if (c == '-')
		res->flags = res->flags | FLG_MINUS;
	else if (c == ' ')
		res->flags = res->flags | FLG_SPACE;
	else if (c == '+')
		res->flags = (res->flags & (~FLG_SPACE)) | FLG_PLUS;
	else if (c == '#')
		res->flags = res->flags | FLG_HASH;
	else if (c == '0')
		res->flags = res->flags | FLG_ZERO;
}
