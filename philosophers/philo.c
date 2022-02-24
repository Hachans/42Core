/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:32 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/24 17:48:47 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	init(t_data *philo, char **argv)
{
	philo->number_of_philosophers = argv[1];
	philo->time_to_die = argv[2];
	philo->time_to_eat = argv[3];
	philo->time_to_sleep = argv[4];
}
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_data	philo;

	if (argc != 5)
	{
		write(2, "5 arguments not passed.\n", 25);
		exit(0);
	}
	init(&philo, argv);
	printf("%s\n", philo.number_of_philosophers);
	printf("%s\n", philo.time_to_die);
	printf("%s\n", philo.time_to_eat);
	printf("%s\n", philo.time_to_sleep);
	return 0;
}