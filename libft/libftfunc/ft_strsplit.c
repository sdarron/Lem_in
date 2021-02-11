/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:09:14 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 19:07:17 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	if (s[0] != c)
		k++;
	while (s[i])
	{
		if ((s[i] != c) && (s[i - 1] == c))
			k++;
		i++;
	}
	return (k + 1);
}

static int	ft_isspace(char cc, char c)
{
	if (cc == c)
		return (1);
	return (0);
}

static void	fullmatrix(char ***m, const char *str, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i], c))
		{
			(*m)[j][k] = str[i];
			k++;
		}
		if ((i != 0) && ft_isspace(str[i], c) && !ft_isspace(str[i - 1], c))
		{
			(*m)[j][k] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	if (k != 0)
		(*m)[j][k] = '\0';
}

static void	memmatrix(char ***mm, const char *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (!ft_isspace(s[i], c))
			k++;
		if ((i != 0) && (ft_isspace(s[i], c)) && (!ft_isspace(s[i - 1], c)))
		{
			(*mm)[j] = (char*)malloc(k + 1);
			j++;
			k = 0;
		}
		i++;
	}
	if (k != 0)
	{
		(*mm)[j] = (char*)malloc(k + 1);
		j++;
	}
	(*mm)[j] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**mm;

	if (!s)
		return (NULL);
	mm = (char**)malloc(countwords(s, c) * sizeof(char*));
	if (!mm)
		return (NULL);
	memmatrix(&mm, s, c);
	fullmatrix(&mm, s, c);
	return (mm);
}
