/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:07:28 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/16 21:18:54 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int	size_a;
	int	size_b;
	int	*a;
	int	*b;
	int	bits;
	int	value;
}				t_data;

long	int_check(char *nptr);
int		check_input(int *input, int argc, char *argv[]);
void	check_double(int *input, int len);
int		is_sorted(t_data *stack);
void	small_sort(t_data *stack);
void	big_sort(t_data *stack);
void	arr_dup(int *src, int *dst, int len);
void	get_low_value(t_data *stack);
void	final_sort(t_data *stack);

void	sa(t_data *stack);
void	sb(t_data *stack);
void	ss(t_data *stack);
void	pa(t_data *stack);
void	pb(t_data *stack);
void	ra(t_data *stack);
void	rb(t_data *stack);
void	rr(t_data *stack);
void	rra(t_data *stack);
void	rrb(t_data *stack);
void	rrr(t_data *stack);
void	sort2(t_data *stack);
void	sort3(t_data *stack);
void	sort4(t_data *stack);
void	sort5(t_data *stack);

#endif