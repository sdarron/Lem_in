/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:10:28 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 20:12:40 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	firstpart(long long *n, long long *k, int *i, int *f)
{
	*f = 0;
	if (*n < 0)
	{
		(*f) = 1;
		(*n) = (*n) * (-1);
	}
	*k = 1;
	*i = 0;
	while (((*n) / (*k)) > 0)
	{
		(*k) = (*k) * 10;
		(*i)++;
	}
}

static void	secondpart(long long *k, int *i, int *f, long long *nn)
{
	firstpart(nn, k, i, f);
	if (*nn == 0)
	{
		*i = 1;
		*k = 10;
	}
}

char		*ft_itoa(int n)
{
	long long	k;
	long long	nn;
	int			i;
	int			f;
	char		*s;

	nn = n;
	secondpart(&k, &i, &f, &nn);
	s = (char*)malloc(i + f + 1);
	if (!s)
		return (NULL);
	i = 0;
	if (f)
		s[i++] = '-';
	while (k > 1)
	{
		k = k / 10;
		s[i] = nn / k + '0';
		i++;
		nn = nn % k;
	}
	s[i] = '\0';
	return (s);
}
