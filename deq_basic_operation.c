/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_basic_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:36:02 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 19:38:50 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void push_top_b(t_deq *deq, t_node *node)
{
	if (deq->b_size == 0)
	{
		deq->b_top = node;
		deq->b_bot = node;
	}
	else if (deq->b_size == 1) // 이중 연결리스트 때문에 일어나는 일일
	{
		deq->b_bot->prev = node;
		node->next = deq->b_top;
		deq->b_top = node;
	}
	else
	{
		deq->b_top->prev = node;
		node->next = deq->b_top;
		deq->b_top = node;	
	}
	deq->b_size++;
}

void push_top_a(t_deq *deq, t_node *node)
{
	if (deq->a_size == 0)
	{
		deq->a_top = node;
		deq->a_bot = node;
	}
	else if (deq->a_size == 1)
	{
		deq->a_bot->prev = node;
		node->next = deq->a_top;
		deq->a_top = node;
	}
	else
	{
		deq->a_top->prev = node;
		node->next = deq->a_top;
		deq->a_top = node;	
	}
	deq->a_size++;
}

void push_bot_a(t_deq *deq_a, t_node *node)
{
	if (deq_a->a_size == 0)
	{
		deq_a->a_top = node;
		deq_a->a_bot = node;
	}
	else if (deq_a->a_size == 1)
	{
		deq_a->a_top->next = node;
		deq_a->a_bot = node;
		deq_a->a_bot->prev = deq_a->a_top;
	}
	else
	{
		deq_a->a_bot->next = node;
		node->prev = deq_a->a_bot;
		deq_a->a_bot = node;
	}
	deq_a->a_size++;
}

void push_bot_b(t_deq *deq_b, t_node *node)
{
	if (deq_b->b_size == 0)
	{
		deq_b->b_top = node;
		deq_b->b_bot = node;
	}
	else if (deq_b->b_size == 1)
	{
		deq_b->b_top->next = node;
		deq_b->b_bot = node;
		deq_b->b_bot->prev = deq_b->b_top;
	}
	else
	{
		deq_b->b_bot->next = node;
		node->prev = deq_b->b_bot;
		deq_b->b_bot = node;
	}
	deq_b->b_size++;
}

t_node*	pop_top(t_deq *deq)
{
	t_node *temp;
	temp = deq->a_top;
	
	if (is_empty(deq) == 1)
		return (NULL);
	if (deq->a_size == 1)
	{
		deq->a_top = NULL;
		deq->a_bot = NULL;
	}
	else
	{
		deq->a_top = temp->next;
		deq->a_top->prev = NULL;
	}
	temp->next = NULL;
	deq->a_size--;
	return (temp);
} 

t_node* pop_bot(t_deq *deq)
{
	t_node *temp;
	temp = deq->a_bot;

	if (is_empty(deq) == 1)
		return (NULL);
	if (deq->a_size == 1)
	{
		deq->a_top = NULL;
		deq->a_bot = NULL;
	}
	else
	{
		deq->a_bot = temp->prev;
		deq->a_bot->next = NULL;
	}
	temp->prev = NULL;
	deq->a_size--;
	return (temp);
}