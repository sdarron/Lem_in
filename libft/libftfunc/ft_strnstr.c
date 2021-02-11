/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:48:57 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/12 18:10:53 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strlength(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int len2;

	i = 0;
	len2 = strlength((char*)needle);
	while ((haystack[i]) && (i < (int)len - len2 + 1))
	{
		j = 0;
		while (needle[j] && (haystack[i + j] == needle[j]))
			j++;
		if (!needle[j])
			return (&((char*)haystack)[i]);
		i++;
	}
	if (needle[0] == '\0')
		return ((char*)haystack);
	return (NULL);
}
