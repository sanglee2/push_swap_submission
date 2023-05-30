/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:48:05 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/29 22:30:59 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void act_command(t_deq* deq_a, t_deq* deq_b, char *str)
{
	if(ft_strncmp(str,"pa\n", 3) == 0)
		pa(deq_a, deq_b);
	else if(ft_strncmp(str,"pb\n",3) == 0)
		pb(deq_a, deq_b);
	else if(ft_strncmp(str,"sa\n",3) == 0)
		sa(deq_a);
	else if(ft_strncmp(str,"sb\n",3) == 0)
		sb(deq_b);
	else if(ft_strncmp(str,"ss\n",3) == 0)
		ss(deq_a, deq_b);
	else if(ft_strncmp(str,"ra\n",3) == 0)
		ra(deq_a);
	else if(ft_strncmp(str,"rra\n",4) == 0)
		rra(deq_a);
	else if(ft_strncmp(str,"rb\n",3) == 0)
		rb(deq_a);
	else if(ft_strncmp(str,"rrb\n",4) == 0)
		rrb(deq_b);
	else if(ft_strncmp(str,"rr\n",3) == 0)
		rr(deq_a, deq_b);
	else if(ft_strncmp(str,"rrr\n",4) == 0)
		rrr(deq_a, deq_b);
	else
		KO();
}

void ft_checker(t_deq* deq_a, t_deq* deq_b)
{
	char* temp;

	while(1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			break;
		act_command(deq_a, deq_b, temp);
		free(temp);
	}
	if(deq_b->b_size != 0||!check_sort(deq_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int main(int ac, char **av)
{
    t_deq* deq_a;
    t_deq* deq_b;
	if (check_arg(ac, av) == 1)
		return (0);
	deq_a = parse(ac,av,1);	
    deq_b = malloc_deq_b();
	if(check_duplicate_arg(deq_a) == 1)
	{
		ft_free_deq_a(deq_a);
		ft_error();
	}
	deq_a->a_size = get_deq_a_size(deq_a);
	make_arg_arr(deq_a);
    content_trans_idx(deq_a);
	deq_print(deq_a);
	ft_checker(deq_a, deq_b);
	deq_print(deq_a);
	ft_free_deq_a(deq_a);
    ft_free_deq_b(deq_b);  
    return (0);
}