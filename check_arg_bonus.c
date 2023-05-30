/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:09:19 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/29 21:31:51 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int check_arg(int ac, char **av)
{
    int i;

    i = 1;
    if (ac < 2)
        return (1);
    while (av[i])
	{
		if(!*av[i])
		{
			ft_error();
			return(1);
		}
		i++;
	}
    return (0);
}