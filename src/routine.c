/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:26:27 by tmerida-          #+#    #+#             */
/*   Updated: 2022/05/24 17:26:29 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int eating(t_philos *philos)
{
	pthread_mutex_lock(&philos->data->forks[philos->left_fork]);
	if (philos->data->dead == 1)
		return (0);
	print_message(philos, "has taken a fork");
	if (philos->data->dead == 1 || philos->data->num_philos == 1)
		return (0);
	pthread_mutex_lock(&philos->data->forks[philos->right_fork]);
	if (philos->data->dead == 1 || philos->data->num_philos == 1)
		return (0);
	print_message(philos, "has taken a fork");
	philos->last_eat = get_time();
	if (philos->data->dead == 1)
		return (0);
	print_message(philos, "is eating");
	t_sleep(philos->data->time_to_eat);
	philos->num_eats--;
	pthread_mutex_unlock(&philos->data->forks[philos->left_fork]);
	pthread_mutex_unlock(&philos->data->forks[philos->right_fork]);
	return (1);
}

int sleeping(t_philos *philos)
{
	if (philos->data->dead == 1)
		return (0);
	print_message(philos, "is sleeping");
	t_sleep(philos->data->time_to_sleep);
	return (1);
}

int thinking(t_philos *philos)
{
	if(philos->data->dead == 1)
		return (0);
	print_message(philos, "is thinking");
	return (1);
} 


void *philo_routine(void *args)
{
	t_philos *philos;
	int i;

	philos = (t_philos *)args;
	
	if (philos->id % 2 == 0)
		t_sleep(200);
	philos->last_eat = get_time();
	while (philos->data->dead == 0 && philos->num_eats != 0)
	{
		if (philos->num_eats == 0 || !eating(philos) || !sleeping(philos) || !thinking(philos))
			break ;
	}
	i = 0;
	while (i < philos->data->num_philos)
	{
		pthread_mutex_unlock(&philos->data->forks[i]);
		i++;
	}
	return (0);
}
