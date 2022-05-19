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


int init_data(int argc, char **argv, t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	if (data->num_philos < 1)
	{
		write(1, "error\n", 6);
		return (0);
	}
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dead = 0;

	if (argc == 6){
		data->num_eats = ft_atoi[5];
		if (data->num_eats < 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
	}
	else
		data->num_eats = -1;
	//mutex init
	return (1);
}
