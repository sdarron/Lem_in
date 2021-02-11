/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:20:29 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 21:35:40 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 0;
	while ((i < n) && (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]))
		i++;
	if (n == i)
		i--;
	return ((int)(((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]));
}
