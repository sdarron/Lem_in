/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor_double_part2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_digit(char *str, va_list *ap)
{
	char				*res;
	unsigned long int	i;

	res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		finish_str(str, ap);
	i = 0;
	res[0] = '1';
	while (i < ft_strlen(str))
	{
		res[i + 1] = str[i];
		i++;
	}
	res[i + 1] = '\0';
	free(str);
	return (res);
}

char	*add_round(char *str, va_list *ap)
{
	long long int i;

	i = ft_strlen(str) - 1;
	while ((i >= 0) && (str[i] == '9'))
	{
		if (str[i] == '.')
			i--;
		str[i] = '0';
		i--;
	}
	if (i == 0)
		str = add_digit(str, ap);
	else
	{
		if (str[i] == '.')
			i--;
		str[i] += 1;
	}
	return (str);
}

char	*add_point(char *str, va_list *ap)
{
	char				*res;
	unsigned long int	i;

	i = 0;
	res = (char*)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!res)
		finish_str(str, ap);
	while (i < ft_strlen(str))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '.';
	res[i + 1] = '\0';
	free(str);
	return (res);
}
