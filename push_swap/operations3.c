/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgars <edgars@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:55:57 by edgars            #+#    #+#             */
/*   Updated: 2022/02/12 11:16:30 by edgars           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *stack)
{
	int	temp_a;
	int	temp_b;
	int	i;

	temp_a = stack->a[stack->size_a - 1];
	temp_b = stack->b[stack->size_b - 1];
	i = stack->size_a;
	while (i-- > 0)
		stack->a[i] = stack->a[i - 1];
	stack->a[0] = temp_a;
	i = stack->size_b;
	while (i-- > 0)
		stack->b[i] = stack->b[i - 1];
	stack->b[0] = temp_b;
	write(1, "rrr\n", 4);
}

void	small_sort(t_data *stack)
{
	if (stack->size_a == 2)
		sort2(stack);
	else if (stack->size_a == 3)
		sort3(stack);
	else if (stack->size_a == 4)
		sort4(stack);
	else if (stack->size_a == 5)
		sort5(stack);
}

void	arr_dup(int *src, int *dst, int len)
{
	while (len >= 0)
	{
		dst[len] = src[len];
		len--;
	}
}
