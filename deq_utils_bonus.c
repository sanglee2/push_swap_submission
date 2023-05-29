/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 04:58:19 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:02:24 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

void deq_print(t_deq* deq)
{
	//index에 관한 한 것
	t_node	*curr;

	curr = deq->a_top;
	while (curr)
	{
		printf("a_top data : %d\n", curr->index);
		curr = curr->next;
	}

	/*curr = deq->a_bot;
	while (curr)
	
		printf("a_bot data : %d\n", curr->content);
		curr = curr->prev;
	}*/
	curr = deq->b_top;
	while (curr)
	{
		printf("b_top data : %d\n", curr->index);
		curr = curr->next;
	}
	/*int i;
	i = 0;
	while (i < deq->arr_size)
	{
		printf("arr[%d] = %d\n", i, deq->arr[i]);
		i++;
	}*/
}