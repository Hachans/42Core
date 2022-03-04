/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:30:23 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/04 21:13:09 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(t_philo *ph, int sleep)
{
	long long	curr;

	curr = get_time();
	pthread_mutex_lock(&ph->info->sleep);
	printf("%lld Philo %d is sleeping\n", get_time() - ph->info->start, ph->id);
	while (get_time() < (curr + sleep))
		usleep(400);
	check_death(ph);
	pthread_mutex_unlock(&ph->info->sleep);
}

void	eat(t_philo *ph, int eating)
{
	long long	curr;

	curr = get_time();
	pthread_mutex_lock(&ph->info->eat);
	ph->last_meal_time = get_time();
	printf("%lld Philo %d is eating\n", get_time() - ph->info->start, ph->id);
	while (get_time() < (curr + eating))
		usleep(400);
	check_death(ph);
	pthread_mutex_unlock(&ph->info->eat);
	ph->eaten_meals++;
}

void	grab_forks(t_philo *ph)
{
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->l_fork]));
	printf("%lld Philo %d took a fork\n", get_time() - ph->info->start, ph->id);
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->r_fork]));
	printf("%lld Philo %d took a fork\n", get_time() - ph->info->start, ph->id);
	eat(ph, ph->info->time_to_eat);
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->l_fork]));
	pthread_mutex_unlock(&(ph->info->fork_mtx[ph->r_fork]));
	my_sleep(ph, ph->info->time_to_sleep);
	printf("%lld Philo %d is thinking\n", get_time() - ph->info->start, ph->id);
}
