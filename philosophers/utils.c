/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:24:04 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/03 21:16:08 by ekraujin         ###   ########.fr       */
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
	long long time;
	
	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

void	lock_all(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->eat);
	pthread_mutex_lock(&ph->info->sleep);
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->l_fork]));
	pthread_mutex_lock(&(ph->info->fork_mtx[ph->r_fork]));
	printf("%lld Philo %d Died\n",get_time() - ph->info->start, ph->id);
	exit(0);
}