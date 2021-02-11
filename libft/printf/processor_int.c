/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_width_int(char *str, t_format form, va_list *ap)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * (form.width + 1));
	if (!result)
		finish_str(str, ap);
	if (form.flags & FLG_MINUS)
		result = add_width_int_right(str, result, form.width);
	else
		result = add_width_int_left(str, result, form.width, form.flags);
	free(str);
	return (result);
}

char	*add_space_int(char *str, va_list *ap)
{
	char				*res;
	unsigned long int	i;

	res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		finish_str(str, ap);
	i = 0;
	res[0] = ' ';
	while (i < ft_strlen(str))
	{
		res[i + 1] = str[i];
		i++;
	}
	res[i + 1] = '\0';
	free(str);
	return (res);
}

char	*processor_d_part2(t_format form, va_list *ap,
		long long int a, char *str)
{
	if (form.is_precision && (form.precision > (long long int)ft_strlen(str)))
		str = add_precision_int(str, form.precision, ap);
	if (a < 0)
		str = add_sign_int(str, '-', ap);
	else if (form.flags & FLG_PLUS)
		str = add_sign_int(str, '+', ap);
	if ((form.flags & FLG_SPACE) && (a >= 0) && !(form.flags & FLG_PLUS))
	{
		if (form.is_width && ((form.width - 1) > (long long int)ft_strlen(str)))
		{
			form.width--;
			str = add_width_int(str, form, ap);
		}
		str = add_space_int(str, ap);
	}
	else if (form.is_width && (form.width > (long long int)ft_strlen(str)))
		str = add_width_int(str, form, ap);
	return (str);
}

char	*processor_d(t_format form, va_list *ap, long long int a)
{
	char	*str;

	if (form.is_precision && (form.precision == 0) && (a == 0))
	{
		str = (char*)malloc(sizeof(char));
		str[0] = '\0';
	}
	else
		str = ft_itoa_base(ft_abs(a), 10);
	if (!str)
		finish(ap);
	if (((a < 0) || (form.flags & FLG_PLUS)) &&
	(form.flags & FLG_ZERO) && form.is_width)
	{
		form.flags = form.flags & (~FLG_ZERO);
		form.is_precision = 1;
		form.precision = (form.precision > (form.width - 1)) ?
				form.precision : (form.width - 1);
		form.is_width = 0;
	}
	str = processor_d_part2(form, ap, a, str);
	return (str);
}

char	*processor_int(t_format *f, va_list *ap)
{
	long long int	a;
	char			*result;
	char			hhd;
	short			hd;
	t_format		form;

	form = *f;
	if (form.size == SIZE_HH)
	{
		hhd = va_arg(*ap, int);
		a = hhd;
	}
	else if (form.size == SIZE_H)
	{
		hd = va_arg(*ap, int);
		a = hd;
	}
	else if (form.size == SIZE_NONE)
		a = va_arg(*ap, int);
	else if (form.size == SIZE_L)
		a = va_arg(*ap, long int);
	else
		a = va_arg(*ap, long long int);
	result = processor_d(form, ap, a);
	return (result);
}
