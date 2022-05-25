#include "../include/philo.h"

void free_info(t_data *data)
{
	int i;

	i = 0;
	free(data->philos);
	while(i < data->num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	pthread_mutex_destroy(&data->message);
	pthread_mutex_destroy(&data->isdead);
	free(data);

}
