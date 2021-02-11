/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:44:28 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/14 17:51:02 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*arr;

	arr = (char*)malloc(size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void*)arr);
}
