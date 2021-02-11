/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:18:16 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/12 16:43:47 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t	i;

	if (!destination && !source)
		return (NULL);
	if (source < destination)
	{
		i = n - 1;
		while (i < n)
		{
			((char*)destination)[i] = ((const char*)source)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char*)destination)[i] = ((const char*)source)[i];
			i++;
		}
	}
	return (destination);
}
