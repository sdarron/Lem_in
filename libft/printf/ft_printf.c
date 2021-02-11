/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_t_format(t_format form, char *strtmp, int *result)
{
	if (form.char_zero == 1)
	{
		if (form.flags & FLG_MINUS)
		{
			ft_putchar('\0');
			ft_putstr(strtmp);
		}
		else
		{
			ft_putstr(strtmp);
			ft_putchar('\0');
		}
		(*result)++;
	}
	else
		ft_putstr(strtmp);
	*result += ft_strlen(strtmp) - 1;
	free(strtmp);
}

void	task(int *i, int *result, const char *line, va_list *ap)
{
	char		*strtmp;
	t_format	form;

	if (line[*i] != '%')
		ft_putchar(line[*i]);
	else
	{
		if (line[*i + 1] == '%')
		{
			(*i)++;
			ft_putchar('%');
		}
		else
		{
			form = parser(i, line, ap);
			strtmp = processor(&form, ap);
			print_t_format(form, strtmp, result);
		}
	}
	(*i)++;
	(*result)++;
}

int		ft_printf(const char *line, ...)
{
	va_list	ap;
	int		i;
	int		result;

	va_start(ap, line);
	i = 0;
	result = 0;
	while (line[i])
		task(&i, &result, line, &ap);
	va_end(ap);
	return (result);
}
