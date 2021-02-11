/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:33:55 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 20:25:16 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && (i < n))
		i++;
	if (i == n)
		i--;
	return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
}
