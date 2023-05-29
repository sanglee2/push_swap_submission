/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 21:50:51 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/20 14:21:57 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pre_setting_deque(t_deq *deq_a, t_deq *deq_b)
{
	int i;
	int pivot;

	i = 0;
	pivot = deq_a->a_size / 2;

	while (deq_a->a_size > 5)
	{
		pb(deq_a, deq_b);
		if (deq_b->b_top->index < pivot)
			rb(deq_b);
		//deq_a->a_size--;
	}
	sort_five_element(deq_a, deq_b);
}

// // 끝나고 3개에 대한 정렬(sorting)이 이루어져야 함.
// // 3개만 남았을 떄, 3개에 대한 정렬.
// // 3개에 대한 정렬들 따로, 따로!
// //ft_3개에 대한 정렬 함수 -- 3개의 정렬을 원하는 함수! 왜 3개만 남기는지에 대해!! // deq_a에서 3개 하드코딩!
// sort_three_element(deq_a);


// // 3그룹이 먼저 넘어온다!


// // sort(== 즉 greedy 끝난 상태)

// // sort 전부 끝나고
// // 위의 상황을 만나서
// // deque를 다시 세팅해준다.
// if (!check_sort(deq_a))
// 	last_setting_deque(deq_a);


void last_setting_deque(t_deq* deq_a)
{
	//int deq_size;
	int min_loc;

	//deq_size = get_deq_a_size(deq_a);
	min_loc = find_min_loc(deq_a);

	if (min_loc > deq_a->a_size / 2)
	{
		min_loc = (deq_a->a_size - min_loc) * -1;
		iterate_rra(deq_a, min_loc);
	}
	iterate_ra(deq_a, min_loc);
}
