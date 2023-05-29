/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:42:13 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 19:40:19 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void act_sort(t_deq *deq_a, t_deq *deq_b, int a_rot, int b_rot)
{	
	if (a_rot < 0)
		iterate_rra(deq_a, a_rot);
	iterate_ra(deq_a, a_rot);
	if (b_rot < 0)
		iterate_rrb(deq_b, b_rot);
	iterate_rb(deq_b, b_rot);
	pa(deq_a, deq_b);
}

void get_rot_count(t_deq* deq_a, t_deq* deq_b)
{
	t_node *temp;
	int a_loc;
	int b_loc;
	int a_rot;
	int b_rot;
	int min;

	temp = deq_b->b_top;
	a_loc = 0;
	b_loc = 0;
	min = INT_MAX;

	while (temp)
	{	
		b_loc = get_b_loc(deq_b, temp->index);
		a_loc = get_a_loc(deq_a, temp->index);
		if (min > ft_abs(a_loc) + ft_abs(b_loc))
		{
			min = ft_abs(a_loc) + ft_abs(b_loc);
			a_rot = a_loc;
			b_rot = b_loc;
		}
		temp = temp->next;
	}
	//printf("min 값 : %d\n", min);
	//printf("a_rot 값 : %d\n", a_rot);
	//printf("b_rot 값 : %d\n", b_rot);
	act_sort(deq_a, deq_b, a_rot, b_rot);
}