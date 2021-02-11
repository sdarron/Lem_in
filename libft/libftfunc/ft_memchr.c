/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:00:12 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/11 16:19:51 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if (((const char*)arr)[i] == (char)c)
			return ((void*)arr + i);
		i++;
	}
	return (NULL);
}
