/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:01:18 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/25 14:47:47 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_input(t_data *stack, int *input)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a - 1)
	{
		j = 0;
		while (j < stack->size_a - 1 - i)
		{
			if (input[j] > input[j + 1])
			{
				temp = input[j + 1];
				input[j + 1] = input[j];
				input[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	indexing(t_data *stack, int *input, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = 1;
		while (j < stack->size_a)
		{
			if (input[i] == sorted[j])
				stack->a[i] = j;
			j++;
		}
		i++;
	}
}

void	free_all(t_data *stack, int *input, int *sorted)
{
	free(input);
	free(stack->a);
	free(stack->b);
	free(sorted);
}

void	initialize(int *input, int len)
{
	t_data	stack;
	int		*sorted;

	stack.size_a = len;
	stack.size_b = 0;
	stack.a = malloc((size_t)len * sizeof(int));
	stack.b = malloc((size_t)len * sizeof(int));
	sorted = malloc((size_t)len * sizeof(int));
	arr_dup(input, sorted, len);
	sort_input(&stack, sorted);
	indexing(&stack, input, sorted);
	if (!is_sorted(&stack))
	{
		if (len <= 5)
			small_sort(&stack);
		else
			big_sort(&stack);
	}
	free_all(&stack, input, sorted);
}

int	main(int argc, char *argv[])
{
	int	*input;

	if (argc <= 1)
		exit(1);
	input = malloc(((size_t)argc - 1) * sizeof(int));
	check_input(input, argc - 1, argv);
	check_double(input, argc - 1);
	initialize(input, argc - 1);
	return (0);
}

// #include <stdio.h>
// int i;
// i = -1;		
// while (++i < stack.size_a)
// 	printf(":%i       :%i\n", stack.a[i], stack.b[i]);