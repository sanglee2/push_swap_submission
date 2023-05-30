/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_hardcoding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:54:27 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 21:48:07 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sort_two_element_a(t_deq *deq_a)
{
    t_node *temp;

    temp = deq_a->a_top;
    if (temp->index > temp->next->index)
        sa(deq_a);
    return ;
}

void sort_two_element_b(t_deq *deq_b)
{
	t_node *temp;

	temp = deq_b->b_top;
	if (temp->index > temp->next->index)
		sb(deq_b);
	return ;
}

void sort_three_element(t_deq* deq_a)
{
    t_node *temp;
    int first;
    int second;
    int third;

    temp = deq_a->a_top;
	first = temp->index;
	second = temp->next->index;
	third = temp->next->next->index;
    if (first > second && third > first)
        sa(deq_a);
    else if (first > second && second > third)
    {
        sa(deq_a);
        rra(deq_a);
    }
    else if (second < third && third < first)
        ra(deq_a);
    else if (second > third && third > first)
    {
        sa(deq_a);
        ra(deq_a);
    }
    else if (first < second && third < first)
        rra(deq_a);
}

void sort_four_element(t_deq* deq_a, t_deq* deq_b)
{
    t_node *temp;
    int min;

    temp = deq_a->a_top;
    min = get_min_value(deq_a);

    while (deq_a->a_top->index != min)
		ra(deq_a);
	pb(deq_a, deq_b);
    sort_three_element(deq_a);
    pa (deq_a, deq_b);
}

void sort_five_element(t_deq* deq_a, t_deq* deq_b)
{
    t_node *temp;
    int max;
    int min;

    temp = deq_a->a_top;
    max = get_max_value(deq_a);
    min = get_min_value(deq_a);
	while (deq_a->a_size > 3)
	{
		if (deq_a->a_top->index == max || deq_a->a_top->index == min)
			pb(deq_a, deq_b);
		else
			ra(deq_a);
	}
    sort_three_element(deq_a);
    sort_two_element_b(deq_b);
    pa (deq_a, deq_b);
    pa (deq_a, deq_b);
	ra (deq_a);
}