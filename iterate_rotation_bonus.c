/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_rotation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:56:10 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:02:46 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


void iterate_ra(t_deq* deq_a, int a_loc)
{
	while(a_loc > 0)
	{
		ra(deq_a);
		a_loc--;
	}

}
void iterate_rra(t_deq* deq_a, int a_loc)
{
	while (a_loc < 0)
	{
		rra(deq_a);
		a_loc++;
	}

}

void iterate_rb(t_deq* deq_b, int b_loc)
{
	while(b_loc > 0)
	{
		rb(deq_b);
		b_loc--;
	}

}

void iterate_rrb(t_deq* deq_b, int b_loc)
{
	while(b_loc < 0)
	{
		rrb(deq_b);
		b_loc++;
	}
}