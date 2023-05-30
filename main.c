/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:18:25 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/30 19:39:04 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_deq* deq_a;
    t_deq* deq_b;
    
    if(check_arg(ac, av) == 1)
        return (0);
	deq_a = parse(ac,av,1);
    //deq_print(deq_a);  
    deq_b = malloc_deq_b();
	if(check_duplicate_arg(deq_a) == 1)
	{
		ft_free_deq_a(deq_a);
        ft_free_deq_b(deq_b);
		ft_error();
	}
    deq_a->a_size = get_deq_a_size(deq_a);
    make_arg_arr(deq_a);
    content_trans_idx(deq_a);
    deq_print(deq_a);   
    sort(deq_a, deq_b);
    if (!check_sort(deq_a))
         last_setting_deque(deq_a);
    deq_print(deq_a);   
    ft_free_deq_a(deq_a);
    ft_free_deq_b(deq_b);  
    return (0);
}