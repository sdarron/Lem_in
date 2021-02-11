/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*nil_string(va_list *ap)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * 4);
	if (!result)
		finish(ap);
	result[0] = '0';
	result[1] = 'x';
	result[2] = '0';
	result[3] = '\0';
	return (result);
}

char	*processor_p(t_format *f, va_list *ap)
{
	char				*result;
	void				*pnt;
	unsigned long int	a;
	t_format			form;

	form = *f;
	form.flags = form.flags & (~FLG_ZERO);
	pnt = va_arg(*ap, void*);
	if (pnt == NULL)
		result = nil_string(ap);
	else
	{
		a = (unsigned long int)pnt;
		result = ft_itoa_base(a, 16);
		if (!result)
			finish(ap);
		if (form.is_precision &&
		(form.precision > (long long int)ft_strlen(result)))
			result = add_precision_int(result, form.precision, ap);
		result = add_alternative_form_x(result, ap);
	}
	if (form.is_width && (form.width > (long long int)ft_strlen(result)))
		result = add_width_int(result, form, ap);
	return (result);
}
