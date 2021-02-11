/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:47:33 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 21:42:06 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t i;

	if (!destination && !source)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char*)destination)[i] = ((const char*)source)[i];
		i++;
	}
	return (destination);
}
