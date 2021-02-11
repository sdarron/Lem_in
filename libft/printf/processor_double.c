/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_frac_part_2(unsigned long int *i, char *str, char *res)
{
	while (*i < ft_strlen(str))
	{
		res[*i] = str[*i];
		(*i)++;
	}
	return (res);
}

char	*add_frac_part(char *str, long long int len, long double a, va_list *ap)
{
	unsigned long int	i;
	long long int		tmp;
	char				*res;

	i = 0;
	res = (char*)malloc(sizeof(char) * (ft_strlen(str) + len + 2));
	if (!res)
		finish_str(str, ap);
	res = add_frac_part_2(&i, str, res);
	res[i] = '.';
	i++;
	while (i < (ft_strlen(str) + len + 1))
	{
		a = a * 10;
		tmp = a;
		res[i] = int_to_char(tmp % 10);
		i++;
	}
	res[i] = '\0';
	tmp = a * 10;
	if ((tmp % 10) >= 5)
		res = add_round(res, ap);
	free(str);
	return (res);
}

char	*processor_double_part2(t_format form,
		long double a, char *str, va_list *ap)
{
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

char	*processor_double(t_format form, va_list *ap, long double tmp)
{
	char			*str;
	long long int	a;
	long double		abs;

	a = tmp;
	abs = (tmp < 0) ? (tmp * (-1)) : tmp;
	str = ft_itoa_base(ft_abs(a), 10);
	if ((form.is_precision == 0) || (form.is_precision && (form.precision < 0)))
		form.precision = 6;
	str = add_frac_part(str, form.precision, abs, ap);
	if (!(form.flags & FLG_HASH) && (form.precision == 0))
		str[ft_strlen(str) - 1] = '\0';
	if ((form.is_width) && (form.width != 0) &&
	((unsigned long)(form.width - 1) > ft_strlen(str)))
		if ((form.flags & FLG_ZERO) && !(form.flags & FLG_MINUS))
			if ((a < 0) || (form.flags & FLG_PLUS))
				str = add_precision_int(str, form.width - 1, ap);
	str = processor_double_part2(form, a, str, ap);
	return (str);
}

char	*processor_f(t_format *f, va_list *ap)
{
	char		*str;
	long double tmp;
	t_format	form;

	form = *f;
	if ((form.size == SIZE_NONE) || (form.size == SIZE_L))
		tmp = va_arg(*ap, double);
	else
		tmp = va_arg(*ap, long double);
	str = processor_double(form, ap, tmp);
	return (str);
}
