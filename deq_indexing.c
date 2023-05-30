/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_indexing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:52:43 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 20:54:55 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	find_max_idx(t_deq *deq)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (i < deq->a_size)
	{
		if (max < deq->arr[i])
			max = deq->arr[i];
		i++;
	}
	i = 0;
	while (i < deq->a_size)
	{
		if (max == deq->arr[i])
		{
			deq->arr[i] = INT_MIN;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	content_trans_idx(t_deq *deq)
{
	int		*idx_arr;
	int		i;
	int		max_idx;
	t_node	*temp;

	idx_arr = (int *)malloc(sizeof(int) * deq->a_size);
	if (!idx_arr)
		return ;
	i = deq->a_size - 1;
	temp = deq->a_top;
	while (i >= 0)
	{
		max_idx = find_max_idx(deq);
		idx_arr[max_idx] = i;
		i--;
	}
	free(deq->arr);
	i = 0;
	while (temp)
	{
		temp->index = idx_arr[i++];
		temp = temp->next;
	}
	free(idx_arr);
}
