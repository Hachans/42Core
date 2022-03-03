/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:20:32 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/03 21:49:03 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	my_sleep(t_philo *ph, int sleep)
{
	long long curr;

	curr = get_time();
	pthread_mutex_lock(&ph->info->sleep);
	printf("%lld Philo %d is sleeping\n",get_time() - ph->info->start, ph->id);
	while (get_time() < (curr + sleep))
	{
		usleep(400);
		check_death(ph);
	}
	pthread_mutex_unlock(&ph->info->sleep);
}

void	eat(t_philo *ph, int eating)
{
	long long	curr;

	curr = get_time();
	pthread_mutex_lock(&ph->info->eat);
	printf("%lld Philo %d is eating\n",get_time() - ph->info->start, ph->id);
	while (get_time() < (curr + eating))
	{
		usleep(400);
		check_death(ph);
	}
	pthread_mutex_unlock(&ph->info->eat);
	ph->eaten_meals++;
	ph->last_meal_time = get_time();
}

void	grab_forks(t_philo *ph)
{
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->l_fork]));
	printf("%lld Philo %d took a fork\n",get_time() - ph->info->start, ph->id);
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->r_fork]));
	printf("%lld Philo %d took a fork\n",get_time() - ph->info->start, ph->id);
	eat(ph, ph->info->time_to_eat);
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->l_fork]));
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->r_fork]));
	my_sleep(ph, ph->info->time_to_sleep);
	printf("%lld Philo %d is thinking\n",get_time() - ph->info->start, ph->id);
}

void	*routine(void *philos)
{
	t_philo	*ph;
	
	ph = (t_philo *) philos;
	if (ph->id % 2)
		usleep(ph->info->time_to_eat);
	while (ph->info->end == 0)
	{
		if (ph->info->meal_flag && ph->eaten_meals == ph->info->number_of_meals)
		{
			printf("%lld Philo %d ate all means\n",get_time() - ph->info->start, ph->id);
			return (0);
		}
		check_death(ph);
		grab_forks(ph);
	}
	if (ph->info->end == 1)
		lock_all(ph);
	return (0);
}

int	init_table(t_data *info)
{
	int	i;
	
	i = 0;
	info->end = 0;
	info->start = get_time();
	while (i < info->number_of_philosophers)
	{
		info->philos[i].last_meal_time = get_time();
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
		info->philos[i].info = info;
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
	// clean_table(&info);
	return (0);
}
