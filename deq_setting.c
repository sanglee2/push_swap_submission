/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:50:51 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 21:03:28 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
{
	int i;
	int pivot;

	i = 0;
	pivot = deq_a->a_size / 2;

	while (deq_a->a_size > 5)
	{
		pb(deq_a, deq_b);
		if (deq_b->b_top->index < pivot)
			rb(deq_b);
	}
	sort_five_element(deq_a, deq_b);
}

void last_setting_deque(t_deq* deq_a)
{
	int min_loc;
	min_loc = find_min_loc(deq_a);

	if (min_loc > deq_a->a_size / 2)
	{
		min_loc = (deq_a->a_size - min_loc) * -1;
		iterate_rra(deq_a, min_loc);
	}
	iterate_ra(deq_a, min_loc);
}
