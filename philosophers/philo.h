/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:34:25 by ekraujin          #+#    #+#             */
/*   Updated: 2022/02/24 17:48:32 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_data
{
	char	*time_to_die;
	char	*time_to_eat;
	char	*time_to_sleep;
	char	*number_of_philosophers;
	
}				t_data;


#endif