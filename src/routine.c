#include "../include/philo.h"


int eating(t_philos *philos)
{
	
	return (1);
}

int sleeping(t_philos *philos)
{

	return (1);
}

int thinking(t_philos *philos)
{

	return (1);
}


int philo_routine(void *args)
{
	t_philos *philos;
	int i;

	philos = (t_philos *)args;
	philos->last_eat = philos->data->init_time;
	if(philos->id % 2 == 0)
		t_sleep(200);
	while(philos->data->dead == 0 && philos->num_eats != 0)
	{
		if(philos->num_eats == 0)
			break ;
		if(!eating(philos))
			break ;
		if(!sleeping(philos))
			break ;
		if(!thinking(philos))
			break ; 
	}
	return (0);
}