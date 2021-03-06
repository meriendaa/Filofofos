/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:14:08 by tmerida-          #+#    #+#             */
/*   Updated: 2022/05/18 19:14:09 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	validate_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				write(1, "error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	start_threads(t_data *data)
{
	int			i;
	pthread_t	*thread;

	i = -1;
	thread = (pthread_t *)malloc(sizeof(pthread_t) * data->num_philos);
	if (!thread)
		return (0);
	data->init_time = get_time();
	while (++i < data->num_philos)
	{
		pthread_create(&thread[i], NULL,
			&philo_routine, (void *)(&data->philos[i]));
	}
	while (42)
		if (check_philo_dead(data))
			break ;
	i = 0;
	while (thread[i])
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	free(thread);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (validate_arg(argc, argv))
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (!init_data(argc, argv, data) || !init_forks(data) || !init_philos(data))
		return (0);
	start_threads(data);
	free_info(data);
	return (0);
}
