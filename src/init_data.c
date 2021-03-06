/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:12:27 by tmerida-          #+#    #+#             */
/*   Updated: 2022/05/19 19:12:29 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->num_philos < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	data->dead = 0;
	data->eat_complete = 0;
	pthread_mutex_init(&data->message, NULL);
	pthread_mutex_init(&data->isdead, NULL);
	data->num_eats = -1;
	if (argc == 6)
		data->num_eats += (ft_atoi(argv[5]) + 1);
	return (1);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (0);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philos) * data->num_philos);
	if (!data->philos)
		return (0);
	while (i < data->num_philos -1)
	{
		data->philos[i].id = i + 1;
		data->philos[i].left_fork = i + 1;
		data->philos[i].right_fork = i;
		data->philos[i].dead = 0;
		data->philos[i].num_eats = data->num_eats;
		data->philos[i].data = data;
		i++;
	}
	data->philos[i].id = i + 1;
	data->philos[i].left_fork = 0;
	data->philos[i].right_fork = i;
	data->philos[i].dead = 0;
	data->philos[i].num_eats = data->num_eats;
	data->philos[i].data = data;
	return (1);
}
