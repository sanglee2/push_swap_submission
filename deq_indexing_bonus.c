/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_indexing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 02:52:43 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:02:09 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <limits.h>

int find_max_idx(t_deq *deq)
{
	int max;
	int i;

	max  = INT_MIN;
	i = 0;

	while (i < deq->a_size)
	{
		if (max < deq->arr[i])
			max = deq->arr[i];
		i++;
	}

	i = 0;
	while (i < deq->a_size)
	{
		// 계속 순차적인 아래의 max값을 찾아내게 되는 신묘한 방법!
		// 기본 c언어, C언어를 배울 때, 기본적으로 갈고 닦아야 하는 기본적인 내용!
		if (max == deq->arr[i])
		{
			deq->arr[i] = INT_MIN;
			return (i);
		}
		i++;
	}
	return (-1);	
}

void content_trans_idx(t_deq *deq)
{
	int *idx_arr;
	int i;
	int max_idx;
	t_node* temp;


	deq->a_size = get_deq_a_size(deq);
	idx_arr = (int *)malloc(sizeof(int) * deq->a_size);
	if (!idx_arr)
		return ;
		//ft_error();
	i = deq->a_size - 1;
	temp = deq->a_top;

	while (i >= 0)
	{
		max_idx = find_max_idx(deq);
		idx_arr[max_idx] = i;
		i--;
	}
	free(deq->arr);

	i = 0;
	while(temp)
	{
		temp->index = idx_arr[i++];
		temp = temp->next;
	}
	free(idx_arr);



	// // 전부 다 update해준 후, free해서 들어가기!
	// free (deq->arr);
	// deq->arr = idx_arr;
}
