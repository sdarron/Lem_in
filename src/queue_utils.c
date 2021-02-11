/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warchiba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:57:24 by warchiba          #+#    #+#             */
/*   Updated: 2020/11/12 17:57:26 by warchiba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_int	*pop_first_from_queue(t_int *queue)
{
	t_int	*tmp;

	tmp = queue->next;
	free(queue);
	return (tmp);
}

void	add_to_queue(t_int *queue, t_int *tmp, int *visited, t_map *map)
{
	int		prev;

	prev = queue->data;
	while (queue->next)
		queue = queue->next;
	while (tmp)
	{
		if (visited[tmp->data] == -1)
		{
			visited[tmp->data] = prev;
			queue->next = (t_int*)malloc(sizeof(t_int));
			if (!queue->next)
				exit_func(map, 0);
			queue->next->data = tmp->data;
			queue->next->next = NULL;
			queue = queue->next;
		}
		tmp = tmp->next;
	}
}

t_int	*init_queue(t_map *map)
{
	t_int	*queue;

	queue = (t_int*)malloc(sizeof(t_int));
	if (!queue)
		exit_func(map, 0);
	queue->data = 0;
	queue->next = NULL;
	return (queue);
}

void	free_queue(t_int *queue)
{
	t_int	*tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}
