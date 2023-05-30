/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:16:22 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 19:56:07 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_deq_a_size(t_deq *deq_a)
{
	t_node* temp;
	int size;

	temp = deq_a->a_top;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

int get_deq_b_size(t_deq *deq_b)
{
	t_node* temp;
	int size;

	temp = deq_b->b_top;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}