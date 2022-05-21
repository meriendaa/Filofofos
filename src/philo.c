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


int validate_arg(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if(ft_isdigit(argv[i][j]) == 0){
				write(1, "error\n", 6);
				return (1);
			}
				
			j++;
		}
		i++;
	}
	return (0);
}


int main(int argc, char **argv)
{
	t_data *data;

	if (argc < 5 || argc > 6)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (validate_arg(argc, argv))
		return (0);

	data = (t_data *)malloc(sizeof(t_data));
	if (!data || !init_data(argc, argv, data))
		return (0);
	if (!init_forks(data))
		return(0);
	if (!init_philos(data))
		return(0);
	//start(data);

/*
	printf("%d\n", data->num_philos);
	printf("%d\n", data->time_to_die);
	printf("%d\n", data->time_to_eat);
	printf("%d\n", data->time_to_sleep);
	printf("%d\n", data->dead);
	printf("%d\n", data->num_eats);
	*/

	return (0);
}