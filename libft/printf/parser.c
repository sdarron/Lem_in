/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		add_flags_to_structure(t_format *res, int *k, const char *line)
{
	while (is_there_any_flag(*k, line) == 1)
	{
		add_flag(line[*k], res);
		(*k)++;
	}
}

void		add_width_to_structure(t_format *res, int *k,
		const char *line, va_list *ap)
{
	if (ft_isdigit(line[*k]) || line[*k] == '*')
	{
		res->is_width = 1;
		if (line[*k] == '*')
		{
			res->width = va_arg(*ap, int);
			if (res->width < 0)
			{
				res->width = (-1) * res->width;
				res->flags = res->flags | FLG_MINUS;
			}
		}
		else
			res->width = ft_atoi(line + *k);
		(*k)++;
		while (ft_isdigit(line[*k]))
			(*k)++;
	}
}

void		add_precision_to_structure(t_format *res, int *k,
		const char *line, va_list *ap)
{
	if (line[*k] == '.')
	{
		(*k)++;
		res->is_precision = 1;
		res->precision = 0;
		if (line[*k] == '*')
		{
			res->precision = va_arg(*ap, int);
			(*k)++;
		}
		else
			res->precision = ft_atoi(line + *k);
		while (ft_isdigit(line[*k]))
			(*k)++;
	}
}

void		add_size_to_structure(t_format *res, int *k, const char *line)
{
	if ((line[(*k) + 1]) && (line[*k] == 'l') && (line[(*k) + 1] == 'l'))
		res->size = SIZE_LL;
	else if ((line[(*k) + 1]) && (line[*k] == 'h') && (line[(*k) + 1] == 'h'))
		res->size = SIZE_HH;
	else if (line[*k] == 'l')
		res->size = SIZE_L;
	else if (line[*k] == 'h')
		res->size = SIZE_H;
	else if (line[*k] == 'L')
		res->size = SIZE_LB;
	while ((line[*k] == 'l') || (line[*k] == 'h') || (line[*k] == 'L'))
		(*k)++;
}

t_format	parser(int *k, const char *line, va_list *ap)
{
	t_format	result;

	init(&result);
	(*k)++;
	add_flags_to_structure(&result, k, line);
	add_width_to_structure(&result, k, line, ap);
	add_precision_to_structure(&result, k, line, ap);
	add_size_to_structure(&result, k, line);
	result.type = line[*k];
	if (!ft_isalpha(result.type) && (result.type != '%'))
	{
		va_end(*ap);
		exit(-1);
	}
	if ((result.flags & FLG_MINUS) && (result.flags & FLG_ZERO))
		result.flags = result.flags & (~FLG_ZERO);
	if (result.is_precision && (result.precision >= 0) &&
	(result.flags & FLG_ZERO) && (result.type != 'f'))
		result.flags = result.flags & (~FLG_ZERO);
	return (result);
}
