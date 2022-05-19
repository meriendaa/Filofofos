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

typedef struct s_philos
{
	int id;
	int right_fork;
	int left_fork;

	struct s_data *data;
} t_philos;

typedef struct s_data
{
	int num_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int num_eats;
	int dead;
	int forks;

} t_data;

int validate_arg(int argc, char **argv);

#endif