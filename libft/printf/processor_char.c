/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_width_string_left(char *result, char *str, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < (len - ft_strlen(str)))
	{
		result[i] = ' ';
		i++;
	}
	j = 0;
	while (j < ft_strlen(str))
	{
		result[i + j] = str[j];
		j++;
	}
	result[i + j] = '\0';
	free(str);
	return (result);
}

char	*add_width_string_right(char *result, char *str, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		result[i] = str[i];
		i++;
	}
	while (i < len)
	{
		result[i] = ' ';
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

char	*add_width_string(char *str, t_format form, va_list *ap)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * (form.width + 1));
	if (!result)
		finish_str(str, ap);
	if (form.flags & FLG_MINUS)
		result = add_width_string_right(result, str, form.width);
	else
		result = add_width_string_left(result, str, form.width);
	return (result);
}

char	*add_precision_string(char *str, unsigned int len, va_list *ap)
{
	unsigned int	i;
	char			*result;

	i = 0;
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		finish(ap);
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

char	*processor_char(t_format *form, va_list *ap)
{
	int		c;
	char	*str;

	c = va_arg(*ap, int);
	str = (char*)malloc(sizeof(char) * 2);
	if (!str)
		finish(ap);
	if (c == '\0')
	{
		form->char_zero = 1;
		form->width--;
	}
	str[0] = (char)c;
	str[1] = '\0';
	if (form->is_width && (form->width > (long long int)ft_strlen(str)))
		str = add_width_string(str, *form, ap);
	return (str);
}
