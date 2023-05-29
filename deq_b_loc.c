/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_b_loc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:19:31 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 07:25:55 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_b_loc(t_deq *deq_b, int b_content)
{
	t_node *temp;
	int cur_loc;
	int b_loc;
	
	temp = deq_b->b_top;
	cur_loc = 0;
	b_loc = 0;

	while (temp)
	{
		if (b_content == temp->index)
			b_loc = cur_loc;
		cur_loc++;
		temp = temp->next;
	}

	// 없애야 할 것들.
	deq_b->b_size = get_deq_b_size(deq_b);

	if (b_loc > deq_b->b_size / 2)
		b_loc = (deq_b->b_size - b_loc) * -1; 
	//printf("rb의 횟수는 : %d\n",b_loc);
	return (b_loc);
}