/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:24:10 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/15 17:35:32 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char*)malloc(len + 1);
	if (!str)
		return (NULL);
	i = start;
	while (i < (size_t)start + len)
	{
		str[i - start] = s[i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
