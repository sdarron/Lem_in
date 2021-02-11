/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:18:54 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/17 17:18:56 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_quicksort(int arr[], int beg, int end)
{
	int		i;
	int		j;
	int		y;
	int		sup;

	i = beg;
	j = end;
	sup = arr[(beg + end) / 2];
	while (i <= j)
	{
		while (arr[i] < sup)
			i++;
		while (arr[j] > sup)
			j--;
		if (i <= j)
		{
			y = arr[i];
			arr[i++] = arr[j];
			arr[j--] = y;
		}
	}
	if (beg < j)
		ft_quicksort(arr, beg, j);
	if (end > i)
		ft_quicksort(arr, i, end);
}
