/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:31:40 by warchiba          #+#    #+#             */
/*   Updated: 2019/09/17 23:39:39 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*elem;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if ((res = ft_lstnew(tmp->content, tmp->content_size)))
	{
		elem = res;
		lst = lst->next;
		while (lst)
		{
			tmp = (*f)(lst);
			if (!(elem->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			elem = elem->next;
			lst = lst->next;
		}
	}
	return (res);
}
