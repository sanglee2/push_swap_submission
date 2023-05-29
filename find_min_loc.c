/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_loc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:47:56 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 08:16:53 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int find_min_loc(t_deq* deq)
{
	t_node* temp;
	int min_a;
	int min_loc;
	int cur_loc;

	temp = deq->a_top;
	min_a = INT_MAX;
	cur_loc = 0;

	// 순회를 할 수 있는 방법에는 여러가지가 있다.
	// deq에 연관되어있는 array가 멤버로 담겨져 있고
	// deq의 크기(size)값이 따로 저장이 되어있으면 가능하다.
	// deq의 노드를 통한 순회
	while (temp)
	{
		if (temp->index < min_a)
		{
			min_a = temp->index;
			min_loc = cur_loc;
		}
		temp = temp->next;
		cur_loc++;
	}
	// if (min_loc > deq->a_size / 2)
	// 	min_loc = (deq->a_size - min_loc) * -1;
	return (min_loc);
}
