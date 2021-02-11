/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:53:15 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 20:37:56 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			preparation(const char *str, int *f)
{
	int i;

	i = 0;
	while (((str[i] >= '\t') && (str[i] <= '\r')) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			*f = 1;
		i++;
	}
	return (i);
}

static long long	lastedit(long long a, int f, int ff)
{
	if (f)
		a = a * (-1);
	if (ff)
	{
		if (f)
			a = 0;
		else
			a = -1;
	}
	return (a);
}

long long int		ft_atoi(const char *str)
{
	long long	a;
	long long	a1;
	int			i;
	int			f;
	int			ff;

	a = 0;
	a1 = 0;
	f = 0;
	ff = 0;
	i = preparation(str, &f);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		a = a * 10 + (str[i] - '0');
		if (a < a1)
		{
			ff = 1;
			break ;
		}
		a1 = a;
		i++;
	}
	a = lastedit(a, f, ff);
	return (a);
}
