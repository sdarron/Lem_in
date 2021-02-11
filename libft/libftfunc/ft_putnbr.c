/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:30:52 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/18 00:00:04 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long long	i;
	long long	nn;
	char		c;

	nn = n;
	if (nn < 0)
	{
		write(1, "-", 1);
		nn = nn * (-1);
	}
	if (nn == 0)
		write(1, "0", 1);
	i = 1;
	while (nn / i != 0)
		i = i * 10;
	while (i > 1)
	{
		i = i / 10;
		c = (char)(nn / i) + '0';
		write(1, &c, 1);
		nn = nn % i;
	}
}
