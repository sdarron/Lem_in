/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:30:20 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/11 18:09:22 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		((char*)destination)[i] = ((const char*)source)[i];
		if (((const char*)source)[i] == (char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
