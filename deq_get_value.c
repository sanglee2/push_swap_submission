/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 04:01:57 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 07:27:25 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int get_max_value(t_deq *deq)
{
	t_node *temp;
	int max;

	temp = deq->a_top;
	max = INT_MIN;
	while (temp)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}


int get_min_value(t_deq *deq)
{
	t_node *temp;
	int min;

	temp = deq->a_top;
	min = INT_MAX;
	while (temp)
	{
		if (min > temp->index)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}