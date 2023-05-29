/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanglee2 <sanglee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:29:45 by sanglee2          #+#    #+#             */
/*   Updated: 2023/05/27 23:02:29 by sanglee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	size_t			i;
	int				sign;
	long long int	num_integer;

	i = 0;
	sign = 1;
	num_integer = 0;
	if (nptr[i] == '-' )
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	if (i == 1 && !ft_isdigit(nptr[1]))
	{
		free(nptr);
		ft_error();
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
		{
			free(nptr);
			ft_error();
		}
		num_integer = num_integer * 10 + nptr[i] - '0';
		i++;
	}
	num_integer = num_integer * sign;
	if(num_integer < INT_MIN || num_integer > INT_MAX)
	{
		free(nptr);
		ft_error();
	}
	return ((int)num_integer);
} 