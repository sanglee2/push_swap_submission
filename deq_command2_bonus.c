/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_command2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:33:31 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 21:51:20 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void rb(t_deq *deq_b)
{
	t_node *temp;
	if (deq_b->b_size < 2)
		return;
	temp = deq_b->b_top;
	deq_b->b_top = deq_b->b_top->next;
	deq_b->b_top->prev = NULL;
	deq_b->b_bot->next = temp;
	temp->prev = deq_b->b_bot;
	deq_b->b_bot = temp;
	deq_b->b_bot->next = NULL;
	write(1, "rb\n", 3);
}

void rrb(t_deq *deq_b)
{
	t_node *temp;
	if (deq_b->b_size < 2)
		return;
	temp = deq_b->b_bot;
	deq_b->b_bot = deq_b->b_bot->prev;
	deq_b->b_bot->next = NULL;
	deq_b->b_top->prev = temp;
	temp->next = deq_b->b_top;
	deq_b->b_top = temp;
	deq_b->b_top->prev = NULL;
	write(1, "rrb\n", 4);
}

void rr(t_deq *deq_a, t_deq* deq_b)
{
	t_node *temp;
	if (deq_a->a_size < 2)
		return;
	temp = deq_a->a_top;
	deq_a->a_top = temp->next;
	deq_a->a_bot->next = temp;
	temp->prev = deq_a->a_bot;
	deq_a->a_bot = temp;
	deq_a->a_bot->next = NULL;
	if (deq_b->b_size < 2)
		return;
	temp = deq_b->b_top;
	deq_b->b_top = deq_b->b_top->next;
	deq_b->b_top->prev = NULL;
	deq_b->b_bot->next = temp;
	temp->prev = deq_b->b_bot;
	deq_b->b_bot = temp;
	deq_b->b_bot->next = NULL;
	write(1, "rr\n", 3);
}


void rrr(t_deq *deq_a, t_deq* deq_b)
{
	t_node *temp;
	if (deq_a->a_size < 2)
		return;
	temp = deq_a->a_bot;
	deq_a->a_bot = deq_a->a_bot->prev;
	deq_a->a_bot->next = NULL;
	deq_a->a_top->prev = temp;
	temp->next = deq_a->a_top;
	deq_a->a_top = temp;
	deq_a->a_top->prev = NULL;
	if (deq_b->b_size < 2)
		return;
	temp = deq_b->b_bot;
	deq_b->b_bot = deq_b->b_bot->prev;
	deq_b->b_bot->next = NULL;
	deq_b->b_top->prev = temp;
	temp->next = deq_b->b_top;
	deq_b->b_top = temp;
	deq_b->b_top->prev = NULL;
	write(1, "rrr\n", 4);
}