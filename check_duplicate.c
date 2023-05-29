/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:19:57 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/22 22:50:21 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_duplicate_arg(t_deq *deq)
{
	t_node* temp1;
	t_node* temp2;
	temp1 = deq->a_top;

	while(temp1)
	{
		temp2 = temp1->next;
		while(temp2)
		{
			if (temp2->content == temp1->content)
				return (1);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	return (0);
}