/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:47:20 by edgars            #+#    #+#             */
/*   Updated: 2022/02/16 13:37:39 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_data *stack)
{
	if (!is_sorted(stack))
		sa(stack);
}

void	sort3(t_data *stack)
{
	if (!is_sorted(stack))
	{
		if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] \
		&& stack->a[2] < stack->a[0])
			ra(stack);
		else if (stack->a[0] > stack->a[1] \
		&& stack->a[1] > stack->a[2])
		{
			ra(stack);
			sa(stack);
		}
		else if (stack->a[0] < stack->a[1] \
		&& stack->a[0] > stack->a[2])
			rra(stack);
		else if (stack->a[0] > stack->a[1] \
		&& stack->a[2] > stack->a[0])
			sa(stack);
		else
		{
			rra(stack);
			sa(stack);
		}
	}
}

void	get_low_value(t_data *stack)
{
	int	i;

	i = 1;
	stack->value = stack->a[0];
	while (i < stack->size_a)
	{
		if (stack->a[i] < stack->value)
			stack->value = stack->a[i];
		i++;
	}
}

void	sort4(t_data *stack)
{
	get_low_value(stack);
	while (stack->a[0] != stack->value)
		ra(stack);
	pb(stack);
	sort3(stack);
	pa(stack);
}

void	sort5(t_data *stack)
{
	get_low_value(stack);
	while (stack->a[0] != stack->value)
		ra(stack);
	pb(stack);
	get_low_value(stack);
	if (stack->value == stack->a[stack->size_a - 1])
		rra(stack);
	else
	{
		while (stack->a[0] != stack->value)
			ra(stack);
	}
	pb(stack);
	sort3(stack);
	pa(stack);
	pa(stack);
}
