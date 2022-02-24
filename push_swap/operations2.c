/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgars <edgars@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:54:32 by edgars            #+#    #+#             */
/*   Updated: 2022/02/12 11:16:25 by edgars           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *stack)
{
	int	temp;
	int	i;

	temp = stack->a[0];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->size_a - 1] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_data *stack)
{
	int	temp;
	int	i;

	temp = stack->b[0];
	i = -1;
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[stack->size_b - 1] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_data *stack)
{
	int	temp_a;
	int	temp_b;
	int	i;

	temp_a = stack->a[0];
	temp_b = stack->b[0];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[stack->size_a - 1] = temp_a;
	i = -1;
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[stack->size_b - 1] = temp_b;
	write(1, "rr\n", 3);
}

void	rra(t_data *stack)
{
	int	temp;
	int	i;

	temp = stack->a[stack->size_a - 1];
	i = stack->size_a;
	while (i-- > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_data *stack)
{
	int	temp;
	int	i;

	temp = stack->b[stack->size_b - 1];
	i = stack->size_b;
	while (i-- > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = temp;
	write(1, "rrb\n", 4);
}
