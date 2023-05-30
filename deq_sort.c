/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 03:55:00 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 21:36:27 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
#include<limits.h>

void    sort(t_deq *deq_a, t_deq *deq_b)
{
    t_node *temp;
    temp = 0;
    if (deq_a->a_size == 1)
        return ;
    else if (deq_a->a_size == 2 && !check_sort(deq_a))
        sort_two_element_a(deq_a);
    else if (deq_a->a_size == 3 && !check_sort(deq_a))
        sort_three_element(deq_a);
    else if (deq_a->a_size == 4 && !check_sort(deq_a))
        sort_four_element(deq_a, deq_b);
    else if (deq_a->a_size == 5 && !check_sort(deq_a))
        sort_five_element(deq_a, deq_b);
    else if (!check_sort(deq_a))
    {
        pre_setting_deque(deq_a, deq_b);
        while(deq_b->b_top)
            get_rot_count(deq_a, deq_b, temp);
    }       
}
