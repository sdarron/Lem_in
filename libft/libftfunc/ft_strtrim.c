/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:53:29 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/15 19:02:39 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t'))
		return (1);
	return (0);
}

static int	findk(const char *s)
{
	int		j;
	int		k;

	j = 0;
	k = -1;
	while (s[j])
	{
		if (!ft_isspace(s[j]))
			k = j;
		j++;
	}
	if (k == -1)
		k = j - 1;
	return (k);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	k = findk(s);
	str = (char*)malloc(k - i + 2);
	if (!str)
		return (NULL);
	j = 0;
	while (i + j <= k)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
