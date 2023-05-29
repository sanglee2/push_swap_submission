/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deq_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 08:18:15 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/26 20:26:23 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_deq* create()
{
	t_deq *deq;
	deq = (t_deq *)malloc(sizeof(t_deq) * 1);
	if(!deq)
		return(0);

	return(deq);
}

void init_deq(t_deq *deq)
{
	deq->a_top = 0;
	deq->a_bot = 0;
	deq->a_size = 0;
	deq->b_top = 0;
	deq->b_bot = 0;
	deq->b_size = 0;
	deq->arr = 0;
}

int is_empty(t_deq* deq)
{
	return (deq->a_top == 0);
}

t_node* init_node(int arg)
{
	t_node *node;
	node = (t_node *)malloc(sizeof(t_node) * 1);
	if (!node)
		return(0);
	
	node->prev = NULL;
	node->content = arg;
	//node->index = 0;
	node->next = NULL;
	return (node);	
}

// t_deq *configuration_deq(int ac, char *av[])
// {
// 	t_deq* deq_a;
// 	t_node* node;
// 	int arg;
// 	int i;

// 	i = 1;
// 	deq_a = create();
// 	init_deq(deq_a);

// 	// 노드가 계속 바뀌면서 생성이 되고 
// 	// 새로운 노드들이 deq에 차곡차곡 쌓이는지 확인해주는 함수
// 	while(i < ac)
// 	{
// 		// 문자열을 인수로 쪼개주고, 문자->정수로 바꿔서 인수화 해주는 암튼 -- ft_atoi
// 		// 우리가 libft에서 썼던 원 atoi함수 기능적인 부분 헤지지 않게
// 		arg = ft_atoi(av[i]);
// 		//arg = av[i];
// 		node = init_node(arg); // 이름이 똑같은 node가 문제? 포인터인 node가 문제?
// 		push_bot(deq_a, node); // 노드라는게 계속 다른게 할당 되어야 할 텐데..
// 		i++;
// 	}
// 	return (deq_a);
// }