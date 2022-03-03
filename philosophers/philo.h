/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:34:25 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/03 21:16:39 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int			id;
	int			l_fork;
	int			r_fork;
	int			eaten_meals;
	long long	last_meal_time;
	pthread_t	thrd_id;
	struct s_data	*info;
	struct timeval	tp;
}				t_philo;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				meal_flag;
	int				number_of_philosophers;
	int				end;
	long long		start;
	pthread_mutex_t	eat;
	pthread_mutex_t	sleep;
	pthread_mutex_t	*fork_mtx;
	t_philo			*philos;
}				t_data;

// utils.c
int			int_check(char *nptr);
long long	get_time(void);
void	lock_all(t_philo *ph);

// check.c
int			check_args(t_data *info, int argc, char **argv);
void		check_death(t_philo *ph);

#endif