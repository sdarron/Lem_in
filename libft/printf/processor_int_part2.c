/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_int_part2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_precision_int(char *str, long unsigned int k, va_list *ap)
{
	char				*result;
	long unsigned int	i;
	long unsigned int	j;

	result = (char*)malloc(sizeof(char) * (k + 1));
	if (!result)
		finish_str(str, ap);
	j = 0;
	while (j < (k - ft_strlen(str)))
	{
		result[j] = '0';
		j++;
	}
	i = 0;
	while (i < ft_strlen(str))
	{
		result[j] = str[i];
		j++;
		i++;
	}
	free(str);
	result[j] = '\0';
	return (result);
}

char	*add_sign_int(char *str, char c, va_list *ap)
{
	char				*result;
	long unsigned int	i;

	result = (char*)malloc(ft_strlen(str) + 2);
	if (!result)
		finish_str(str, ap);
	i = 0;
	result[0] = c;
	while (i < ft_strlen(str))
	{
		result[i + 1] = str[i];
		i++;
	}
	result[i + 1] = '\0';
	free(str);
	return (result);
}

char	*add_width_int_left(char *str, char *result,
							long unsigned int len, long unsigned int flags)
{
	char				c;
	long unsigned int	i;
	long unsigned int	j;

	i = 0;
	j = 0;
	c = (flags & FLG_ZERO) ? '0' : ' ';
	while (i < (len - ft_strlen(str)))
	{
		result[i] = c;
		i++;
	}
	while (j < ft_strlen(str))
	{
		result[i + j] = str[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*add_width_int_right(char *str, char *result, long unsigned int len)
{
	long unsigned int	i;

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
	return (result);
}
