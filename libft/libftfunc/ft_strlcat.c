/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:32:49 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/12 13:48:22 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlength(const char *str)
{
	int k;

	k = 0;
	while (str[k])
		k++;
	return (k);
}

size_t		ft_strlcat(char *restrict dst,
		const char *restrict src, size_t size)
{
	size_t len1;
	size_t len2;
	size_t j;

	len1 = (size_t)ft_strlength(dst);
	len2 = (size_t)ft_strlength(src);
	j = 0;
	if (len1 > size)
		return (size + len2);
	while ((src[j]) && (len1 + j < size - 1))
	{
		dst[len1 + j] = src[j];
		j++;
	}
	dst[len1 + j] = '\0';
	return (len1 + len2);
}
