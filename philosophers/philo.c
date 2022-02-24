/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:32 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/24 18:48:18 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checkninit(t_data *philo, int argc, char **argv)
{
	philo->number_of_philosophers = int_check(argv[1]);
	philo->time_to_die = int_check(argv[2]);
	philo->time_to_eat = int_check(argv[3]);
	philo->time_to_sleep = int_check(argv[4]);
	if (philo->number_of_philosophers < 0 || philo->time_to_die < 0 \
		|| philo->time_to_eat < 0 || philo->time_to_sleep < 0)
	{
		write(2, "Invalid argument\n", 18);
		exit (0);
	}
	philo->forks = philo->number_of_philosophers;
	if (argc == 6)
	{
		philo->number_of_times_each_philosopher_must_eat = int_check(argv[5]);
		if (philo->number_of_times_each_philosopher_must_eat < 0)
		{
			write(2, "Invalid argument\n", 18);
			exit (0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	philo;

	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid argument count.\n", 25);
		exit(0);
	}
	checkninit(&philo, argc, argv);
	return (0);
}
