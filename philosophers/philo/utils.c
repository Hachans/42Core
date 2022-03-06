/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:24:04 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/06 15:55:40 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	int_check(char *nptr)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (!*nptr)
		return (-1);
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-' || nptr[++i] == '\0')
			return (-1);
	}
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			result = result * 10 + (nptr[i] - '0');
		else
			return (-1);
		i++;
	}
	return (result);
}

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

void	lock_all(t_data *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->eat);
	pthread_mutex_lock(&info->sleep);
	while (i < info->number_of_philosophers)
	{
		pthread_mutex_destroy(&(info->fork_mtx[i]));
		i++;
	}
	printf("%lld Philo %d Died\n", get_time() - info->start + 1, \
			info->philos->id);
}

void	clean_table(t_data *info)
{
	free(info->philos);
	free(info->fork_mtx);
}

void	handle_one(t_data *info)
{
	printf("0 Philo 1 has taken a fork\n");
	sleep(1);
	printf("%d Philo 1 Died\n", info->time_to_die + 1);
	exit(0);
}
