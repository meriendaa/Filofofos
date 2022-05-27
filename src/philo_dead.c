/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:01:51 by tmerida-          #+#    #+#             */
/*   Updated: 2022/05/24 18:01:52 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_philo_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->isdead);
		if ((data->philos[i].last_eat != 0 && data->time_to_die
				< (int)(get_time() - data->philos[i].last_eat)))
		{
			if (data->dead == 0)
				print_message(&data->philos[i], "died");
			data->dead = 1;
			return (1);
		}
		if (data->eat_complete == data->num_philos)
			return (1);
		if (data->philos[i].num_eats == 0)
			data->eat_complete++;
		pthread_mutex_unlock(&data->isdead);
		i++;
	}
	return (0);
}
