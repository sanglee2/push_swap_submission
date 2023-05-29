/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_command1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:15:24 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 18:48:12 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 명령어 관련 작성부분

void pa(t_deq *deq_a, t_deq *deq_b) // stack에 대한 전부가 넘어와야 되나? --> 되는가?
{
	t_node *temp;

	if (deq_b->b_size < 1)
		return ;

	//deq_b의 크기 0이 아니라, 넘길 건덕지가 있는 경우. content가 1개라도 있을 때.
	else
	{
		temp = deq_b->b_top; // b의 제일 위를 가리키게 해야 함.

		// 넘기고 나서 deq_b의 멤버에 대한 노드들 초기화
		if (deq_b->b_size == 1)
		{
			deq_b->b_top = NULL;
			deq_b->b_bot = NULL;
		}

		// 1개 이상인 일반적인 경우면, 그렇게 진행을 해도 가능할 듯 하다
		if (deq_b->b_size > 1)
		{
			deq_b->b_top = deq_b->b_top->next;
			deq_b->b_top->prev = NULL;
		}

		// 뽑아내는 본진인 a가 아무것도 없다면 발생하는 문제에 대해서
		if (deq_a->a_size < 1)
		{
			temp->next = NULL;
			temp->prev = NULL;
			deq_a->a_top = temp;
			deq_a->a_bot = temp;
		}
		push_top_a(deq_a, temp);
	}
	//deq_a->a_size = deq_a->a_size + 1;
	deq_b->b_size = deq_b->b_size - 1;
	write(1, "pa\n", 3);
}

void pb(t_deq *deq_a, t_deq *deq_b)
{
	t_node *temp;

	if (deq_a->a_size < 1)
		return ;
	
	// 
	else
	{
		temp =  deq_a->a_top;

		if (deq_a->a_size == 1)
		{
			deq_a->a_top = NULL;
			deq_a->a_bot = NULL;
		}

		if (deq_a->a_size > 1)
		{
			deq_a->a_top = deq_a->a_top->next;
			deq_a->a_top->prev = NULL;
		}

		if (deq_b->b_size < 1)
		{
			temp->next = NULL;
			temp->prev = NULL;
			deq_b->b_top = temp;
			deq_b->b_bot = temp;
		} 
		push_top_b(deq_b, temp);
	}

	deq_a->a_size = deq_a->a_size - 1;
	//deq_b->b_size = deq_b->b_size + 1;
	write(1, "pb\n", 3);	
}

void sa(t_deq *deq_a)
{
	int temp;
	if (deq_a->a_size < 2)
		return ;

	temp = deq_a->a_top->index;
	deq_a->a_top->index = deq_a->a_top->next->index;
	deq_a->a_top->next->index = temp;	
	write(1, "sa\n", 3);
}

void sb(t_deq *deq_b)
{
	int temp;
	if (deq_b->b_size < 2)
		return ;

	temp = deq_b->b_top->index;
	deq_b->b_top->index = deq_b->b_top->next->index;
	deq_b->b_top->next->index = temp;
	write(1, "sb\n", 3);
}

// sa와 sb를 동시에 한다?

// 유일하게 검증 안 한 ss - 검증 필요
void ss(t_deq *deq_a, t_deq *deq_b)
{
	int temp;
	if (deq_a->a_size < 2)
		return;
	temp = deq_a->a_top->index;
	deq_a->a_top->index = deq_a->a_top->next->index;
	deq_a->a_top->next->index = temp;
	if (deq_b->b_size < 2)
		return;
	temp = deq_b->b_top->index;
	deq_b->b_top->index = deq_b->b_top->next->index;
	deq_b->b_top->next->index = temp;
	write(1, "ss\n", 3);
}

void ra(t_deq *deq_a)
{
	t_node *temp;
	if (deq_a->a_size < 2)
		return;
	temp = deq_a->a_top;
	deq_a->a_top = temp->next;
	//temp->prev = NULL;
	deq_a->a_bot->next = temp;
	temp->prev = deq_a->a_bot;
	deq_a->a_bot = temp;
	deq_a->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void rra(t_deq *deq_a)
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
	write(1, "rra\n", 4);
}






























