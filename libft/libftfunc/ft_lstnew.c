/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:42:44 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 23:00:19 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_mmemcpy(void *destination, const void *source, size_t n)
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

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	if (content)
	{
		list->content = malloc(content_size);
		ft_mmemcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
