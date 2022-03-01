/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:32 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/01 13:22:24 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	grab_forks(t_data *in)
{
	printf("Philosopher %d took a fork\n", in->philos->id);
	pthread_mutex_lock(&(in->fork_mtx[in->philos->l_fork]));
	printf("Philosopher %d took a fork\n", in->philos->id);
	pthread_mutex_lock(&(in->fork_mtx[in->philos->r_fork]));
	printf("Philosopher %d took a fork\n", in->philos->id);
}

int	check_death(t_data *in)
{
	if (!in)
		exit(0);
	long long	curr_time;

	curr_time = get_time();
	printf("%d\n", in->time_to_die);
	if (curr_time > in->philos->last_meal_time + in->time_to_die)
		return (1);
	return (0);
}	

void	*routine(void *info)
{
	t_data	*in;
	
	in = (t_data *) info;
	// printf("Philosopher %d took a fork\n", in->philos->id);
	// pthread_mutex_lock(&(in->fork_mtx[in->philos->l_fork]));
	// printf("Philosopher %d took a fork\n", in->philos->id);
	// pthread_mutex_lock(&(in->fork_mtx[in->philos->r_fork]));
	// printf("Philosopher %d took a fork\n", in->philos->id);
	while (!check_death(in))
	{
	// // grab_forks(info);
	// 	printf("lala\n");
	}
	return (0);
}

int	init_table(t_data *info)
{
	int	i;
	
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_create(&(info->philos[i].thrd_id), NULL, &routine, (void *)&(info->philos[i])))
			return (0);
		i++;
	}
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_join(info->philos[i].thrd_id, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	init_philo(t_data *info)
{
	int	i;
	
	i = 0;
	info->philos = malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!info->philos)
		return (0);
	while (i < info->number_of_philosophers)
	{
		info->philos[i].id = i + 1;
		info->philos[i].l_fork = i;
		info->philos[i].r_fork = (i + 1) % info->number_of_philosophers;
		info->philos[i].last_meal_time = 0;
		info->philos[i].eaten_meals = 0;
		i++;
	}
	info->fork_mtx = malloc(sizeof(t_philo) * info->number_of_philosophers);
	if (!info->fork_mtx)
		return (0);
	i = -1;
	while (++i < info->number_of_philosophers)
		pthread_mutex_init(&(info->fork_mtx[i]), NULL);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	info;

	if (!check_args(&info, argc, argv))
		return (1);
	if (!init_philo(&info))
		return (2);
	init_table(&info);
	printf("Got here\n");
	return (0);
}
