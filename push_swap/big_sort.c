/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:05:52 by edgars            #+#    #+#             */
/*   Updated: 2022/02/16 23:21:42 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	big_sort(t_data *stack)
{
	stack->bits = 0;
	stack->value = stack->size_a - 1;
	while (stack->value >> stack->bits)
		++stack->bits;
	final_sort(stack);
}

void	final_sort(t_data *stack)
{
	int	i;
	int	j;
	int	size;

	size = stack->size_a;
	i = 0;
	while (i < stack->bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack->a[0] >> i) & 1) == 1)
				ra(stack);
			else
				pb(stack);
			j++;
		}
		while (stack->size_b > 0)
			pa(stack);
		i++;
	}
}
