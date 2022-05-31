/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerida- <tmerida-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:26:11 by tmerida-          #+#    #+#             */
/*   Updated: 2022/05/24 17:26:14 by tmerida-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(t_philos *philos, char *str)
{
	pthread_mutex_lock(&philos->data->message);
	if (philos->data->dead == 0 && philos->num_eats != 0)
		printf("[%lld] philo [%d] %s\n",
			(get_time() - philos->data->init_time), philos->id, str);
	pthread_mutex_unlock(&philos->data->message);
}
