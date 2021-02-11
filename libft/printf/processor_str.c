/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*null_string(va_list *ap)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 7);
	if (!str)
		finish(ap);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

char	*zero_string(va_list *ap)
{
	char	*str;

	str = (char*)malloc(sizeof(char));
	if (!str)
		finish(ap);
	str[0] = '\0';
	return (str);
}

int		condition1(t_format form)
{
	if (!form.is_precision)
		return (1);
	else if (form.is_precision && (form.precision >= 6))
		return (1);
	else if (form.is_precision && (form.precision < 0))
		return (1);
	else
		return (0);
}

int		condition2(t_format form, const char *str)
{
	if (form.is_precision)
		if (form.precision >= 0)
			if ((long long int)ft_strlen(str) > form.precision)
				return (1);
	return (0);
}

char	*processor_string(t_format *f, va_list *ap)
{
	char			*str;
	char			*tmp;
	t_format		form;

	form = *f;
	tmp = va_arg(*ap, char*);
	if (tmp == NULL)
		str = null_string(ap);
	else
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(tmp) + 1));
		if (!str)
			finish(ap);
		str = ft_strcpy(str, tmp);
	}
	if (condition2(form, str))
		str = add_precision_string(str, form.precision, ap);
	if (form.is_width && (form.width > (long long int)ft_strlen(str)))
		str = add_width_string(str, form, ap);
	return (str);
}
