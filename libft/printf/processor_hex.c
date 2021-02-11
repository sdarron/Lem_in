/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_alternative_form_x(char *str, va_list *ap)
{
	char			*result;
	unsigned int	i;

	result = (char*)malloc(sizeof(char) * (ft_strlen(str) + 3));
	if (!result)
		finish_str(str, ap);
	result[0] = '0';
	result[1] = 'x';
	i = 0;
	while (i < ft_strlen(str))
	{
		result[i + 2] = str[i];
		i++;
	}
	result[i + 2] = '\0';
	free(str);
	return (result);
}

char	*processor_hex(t_format form, va_list *ap, unsigned long long int a)
{
	char			*str;

	if (form.is_precision && (form.precision == 0) && (a == 0))
		str = zero_string(ap);
	else
		str = ft_itoa_base(a, 16);
	if (!str)
		finish(ap);
	if (a == 0)
		form.flags = form.flags & (~FLG_HASH);
	if ((form.flags & FLG_HASH) && (form.flags & FLG_ZERO) && form.is_width)
	{
		form.flags = form.flags & (~FLG_ZERO);
		form.is_precision = 1;
		form.precision = (form.precision > (form.width - 2)) ?
				form.precision : (form.width - 2);
		form.is_width = 0;
	}
	if (form.is_precision && (form.precision > (long long int)ft_strlen(str)))
		str = add_precision_int(str, form.precision, ap);
	if (form.flags & FLG_HASH)
		str = add_alternative_form_x(str, ap);
	if (form.is_width && (form.width > (long long int)ft_strlen(str)))
		str = add_width_int(str, form, ap);
	return (str);
}

char	*processor_x(t_format *f, va_list *ap)
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
	result = processor_hex(form, ap, a);
	return (result);
}

char	*processor_xx(t_format *form, va_list *ap)
{
	char			*result;
	unsigned int	i;

	i = 0;
	result = processor_x(form, ap);
	while (i < ft_strlen(result))
	{
		result[i] = ft_toupper(result[i]);
		i++;
	}
	return (result);
}
