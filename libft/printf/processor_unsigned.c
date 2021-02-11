/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*processor_unsigned(t_format form, va_list *ap,
		unsigned long long int a)
{
	char	*str;

	if (form.is_precision && (form.precision == 0) && (a == 0))
	{
		str = (char*)malloc(sizeof(char));
		str[0] = '\0';
	}
	else
		str = ft_itoa_base(a, 10);
	if (form.is_precision && (form.precision > (long long int)ft_strlen(str)))
		str = add_precision_int(str, form.precision, ap);
	if (form.is_width && (form.width > (long long int)ft_strlen(str)))
		str = add_width_int(str, form, ap);
	return (str);
}

char	*processor_u(t_format *f, va_list *ap)
{
	unsigned long long int	a;
	char					*result;
	unsigned char			hhd;
	unsigned short int		hd;
	t_format				form;

	form = *f;
	if (form.size == SIZE_HH)
	{
		hhd = va_arg(*ap, unsigned int);
		a = hhd;
	}
	else if (form.size == SIZE_H)
	{
		hd = va_arg(*ap, unsigned int);
		a = hd;
	}
	else if (form.size == SIZE_NONE)
		a = va_arg(*ap, unsigned int);
	else if (form.size == SIZE_L)
		a = va_arg(*ap, unsigned long int);
	else
		a = va_arg(*ap, unsigned long long int);
	result = processor_unsigned(form, ap, a);
	return (result);
}
