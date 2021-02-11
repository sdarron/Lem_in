/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:50:30 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/12 14:01:47 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = &((char*)s)[i];
		i++;
	}
	if ((char)c == '\0')
		str = &((char*)s)[i];
	return (str);
}
