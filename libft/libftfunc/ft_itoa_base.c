/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 12:37:10 by warchiba          #+#    #+#             */
/*   Updated: 2020/08/01 17:41:54 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_digits(unsigned long long int num, int base)
{
	int		k;

	k = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		k++;
	}
	return (k);
}

char	int_to_char_part2(int n)
{
	if (n == 8)
		return ('8');
	else if (n == 9)
		return ('9');
	else if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else
		return ('f');
}

char	int_to_char(int n)
{
	if (n == 0)
		return ('0');
	else if (n == 1)
		return ('1');
	else if (n == 2)
		return ('2');
	else if (n == 3)
		return ('3');
	else if (n == 4)
		return ('4');
	else if (n == 5)
		return ('5');
	else if (n == 6)
		return ('6');
	else if (n == 7)
		return ('7');
	else
		return (int_to_char_part2(n));
}

char	*ft_itoa_base(unsigned long long int num, int base)
{
	char	*result;
	int		k;

	k = count_digits(num, base);
	result = (char*)malloc(k + 1);
	if (!result)
		return (NULL);
	result[k] = '\0';
	while (k > 0)
	{
		result[k - 1] = int_to_char(num % base);
		num = num / base;
		k--;
	}
	return (result);
}
