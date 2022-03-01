/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:43:39 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/01 12:38:26 by ekraujin         ###   ########.fr       */
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
	if (argc == 6)
	{
		info->number_of_meals = int_check(argv[5]);
		info->meal_flag = 1;
	}
	else
	{
		info->number_of_meals = 0;
		info->meal_flag = 0;
	}
	if (info->number_of_philosophers < 1 || info->number_of_philosophers > 200 \
		|| info->time_to_die < 60 || info->time_to_eat < 60 \
		|| info->time_to_sleep < 60 || info->number_of_meals < 0)
	{
		write(2, "Invalid argument count or value.\n", 34);
		return (0);
	}
	return (1);
}