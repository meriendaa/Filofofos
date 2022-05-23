/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:13:50 by tmerida-          #+#    #+#             */
/*   Updated: 2022/05/18 19:13:54 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>


typedef struct s_philos
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				num_eats;
	int				dead;
	long long int	last_eat;
	struct s_data	*data;
} t_philos;

typedef struct s_data
{
	int 			num_philos;
	int 			time_to_die;
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			num_eats;
	int 			dead;
	long long int	init_time;
	t_philos		*philos;
	pthread_mutex_t	*forks;

} t_data;

int				validate_arg(int argc, char **argv);
int				init_data(int argc, char **argv, t_data *data);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);	
int				init_forks(t_data *data);
int				init_philos(t_data *data);
long long int	get_time(void);
int				start_threads(t_data *data);


#endif