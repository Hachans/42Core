/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:43:39 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/04 21:00:54 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(t_data *info, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (0);
	info->number_of_philosophers = int_check(argv[1]);
	info->time_to_die = int_check(argv[2]);
	info->time_to_eat = int_check(argv[3]);
	info->time_to_sleep = int_check(argv[4]);
	info->number_of_meals = 0;
	if (argc == 6)
	{
		info->number_of_meals = int_check(argv[5]);
		info->meal_flag = 1;
	}
	else
		info->meal_flag = 0;
	if (info->number_of_philosophers < 1 || info->number_of_philosophers > 200 \
		|| info->time_to_die < 60 || info->time_to_eat < 60 \
		|| info->time_to_sleep < 60 || info->number_of_meals < 0)
	{
		write(2, "Invalid argument count or value.\n", 34);
		return (0);
	}
	return (1);
}

void	check_death(t_philo *ph)
{
	long long	curr_time;

	curr_time = get_time();
	if (curr_time >= (ph->last_meal_time + ph->info->time_to_die))
		ph->info->end = 1;
}
