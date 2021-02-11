/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:22:47 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/12 16:06:06 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && (haystack[i + j] == needle[j]))
			j++;
		if (!needle[j])
			return (&((char*)haystack)[i]);
		i++;
	}
	if ((haystack[0] == '\0') && (needle[0] == '\0'))
		return ((char*)haystack);
	return (NULL);
}
