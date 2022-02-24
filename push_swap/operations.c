/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgars <edgars@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:50:58 by edgars            #+#    #+#             */
/*   Updated: 2022/02/12 11:16:19 by edgars           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	write(1, "sa\n", 3);
}

void	sb(t_data *stack)
{
	int	temp;

	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "sb\n", 3);
}

void	ss(t_data *stack)
{
	int	temp_a;
	int	temp_b;

	if (stack->size_a > 1 && stack->size_b > 1)
	{
		temp_a = stack->a[0];
		temp_b = stack->b[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = temp_a;
		stack->b[0] = stack->b[1];
		stack->b[1] = temp_b;
	}
	write(1, "ss\n", 3);
}

void	pb(t_data *stack)
{
	int	temp;
	int	i;

	temp = stack->a[0];
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = stack->a[i + 1];
	i = stack->size_b + 1;
	while (i-- > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = temp;
	--stack->size_a;
	++stack->size_b;
	write(1, "pb\n", 3);
}

void	pa(t_data *stack)
{
	int	temp;
	int	i;

	temp = stack->b[0];
	i = stack->size_a;
	while (i-- > 0)
		stack->a[i + 1] = stack->a[i];
	i = -1;
	while (++i < stack->size_b)
		stack->b[i] = stack->b[i + 1];
	stack->a[0] = temp;
	++stack->size_a;
	--stack->size_b;
	write(1, "pa\n", 3);
}
