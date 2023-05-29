/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_a_loc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:19:28 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 07:25:41 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int get_a_loc(t_deq* deq_a, int b_content) //deq_b_b_top_content)
{
	int deq_a_loc;
	int cur_loc;
	int min;
	int min_a;
	t_node* temp;

	deq_a_loc = 0;
	cur_loc = 0;
	min = INT_MAX;
	min_a = INT_MAX;
	temp = deq_a->a_top;

	while (temp)
	{
		if (b_content < temp->index)
		{
			if (min > temp->index - b_content)
			{
				min = temp->index - b_content;
				deq_a_loc = cur_loc;
			}
		}
		temp = temp->next;
		cur_loc++;
	}
	//printf("가장 작은 차이값 min 값은 : %d\n", min);
	// 같을 경우가 있겠지만 괜찮을 거 같아.
	if (min == INT_MAX)
	{
		temp = deq_a->a_top;
		cur_loc = 0;
		while(temp)
		{
			if (temp->index < min_a)
			{
				min_a = temp->index;
				deq_a_loc = cur_loc;
			}
			temp = temp->next;
			cur_loc++;
		}
		//printf("가장 작은 min_a 값은 : %d\n", min_a);
	}
	// 없어져야 할 부분
	deq_a->a_size = get_deq_a_size(deq_a);
	if (deq_a_loc > deq_a->a_size / 2)
		deq_a_loc = (deq_a->a_size - deq_a_loc) * -1;
	//printf("ra횟수는 : %d", deq_a_loc);
	return (deq_a_loc);
}