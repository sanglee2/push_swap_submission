/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_basic_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:36:02 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 05:21:44 by sanglee2         ###   ########.fr       */
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
		//deq->a_top = node;
		//deq->a_top->next = deq->a_bot;
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
	else if (deq->a_size == 1) // 이중 연결리스트 때문에 일어나는 일일
	{
		deq->a_bot->prev = node;
		node->next = deq->a_top;
		//deq->a_top = node;
		//deq->a_top->next = deq->a_bot;
		deq->a_top = node;
	}
	else
	{
		deq->a_top->prev = node;
		//node->prev = NULL;
		node->next = deq->a_top;
		deq->a_top = node;	
	}
	deq->a_size++;
}

void push_bot_a(t_deq *deq_a, t_node *node)
{
	// deq a가 비어있을 때.
	// top 과 bot 모두가 현재 노드를 가리킬 수 있도록.
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
	// deq a가 비어있을 때.
	// top 과 bot 모두가 현재 노드를 가리킬 수 있도록.
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

// pop에 대한 검증은 안 한 거? 한 걸로 되어있으니까
t_node*	pop_top(t_deq *deq)
{
	// 왜 선언을 했을지? 필요한 부분인지
	// 해당 변수를 가리키는 포인터를 선언했다 의미.
	//t_node *node;
	t_node *temp;
	//int arg;


	// node인 deq의 a_top 부분을 계속 이동시키기.
	// 해당노드를 방출하기.
	temp = deq->a_top;

	//deq이 비어있는지 확인.
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
		//deq->a_top = deq->a_top->next;
		deq->a_top->prev = NULL;
	}
	temp->next = NULL; // 다음 노드를 가리키던 거 NULL값으로.
	//free(temp); //왜 필요한지?
	deq->a_size--;
	return (temp);
} 

t_node* pop_bot(t_deq *deq)
{
	t_node *temp;

	temp = deq->a_bot;

	//deq이 비어있는지 확인.
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