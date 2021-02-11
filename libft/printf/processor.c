/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	finish_str(char *str, va_list *ap)
{
	free(str);
	va_end(*ap);
	exit(-1);
}

void	finish(va_list *ap)
{
	va_end(*ap);
	exit(-1);
}

char	*processor_percent(t_format *form, va_list *ap)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 2);
	if (!str)
		finish(ap);
	str[0] = '%';
	str[1] = '\0';
	if (form->is_width && (form->width > (long long int)ft_strlen(str)))
		str = add_width_int(str, *form, ap);
	return (str);
}

char	*processor(t_format *form, va_list *ap)
{
	char	*res;

	if (form->type == '%')
		res = processor_percent(form, ap);
	else if ((form->type == 'd') || (form->type == 'i'))
		res = processor_int(form, ap);
	else if (form->type == 'c')
		res = processor_char(form, ap);
	else if (form->type == 's')
		res = processor_string(form, ap);
	else if (form->type == 'x')
		res = processor_x(form, ap);
	else if (form->type == 'X')
		res = processor_xx(form, ap);
	else if (form->type == 'p')
		res = processor_p(form, ap);
	else if (form->type == 'u')
		res = processor_u(form, ap);
	else if (form->type == 'o')
		res = processor_o(form, ap);
	else if (form->type == 'f')
		res = processor_f(form, ap);
	else
		res = zero_string(ap);
	return (res);
}
