/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_struct_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:13 by root              #+#    #+#             */
/*   Updated: 2021/07/04 23:15:03 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	mutex_destroy(t_philo **philos, size_t mutex_num)
{
	size_t	i;

	i = 0;
	while (i < mutex_num)
	{
		pthread_mutex_destroy(&philos[i]->mutex);
		i++;
	}
	return (ERROR);
}

int	philos_struct_fill_func(t_philo *philo)
{
	if (philo->id % 2)
		philo->philo_eat = philo_eat_odd;
	else
		philo->philo_eat = philo_eat_even;
	philo->philo_sleep = philo_sleep;
	philo->philo_think = philo_think;
	return (0);
}

int	philos_struct_fill_var(t_arguments *arg, struct timeval *time, t_philo *philo, size_t i)
{
	philo->eating = 0;
	philo->id = i + 1;
	philo->arg = arg;
	philo->start_time = time;
	if (pthread_mutex_init(&philo->mutex, NULL))
		return (ERROR);
	return (0);
}

int	philos_struct_fill(t_arguments *arg, t_philo **philos, struct timeval *time)
{
	size_t	i;

	i = 0;
	while (i < (size_t) arg->num_of_philo)
	{
		if (philos_struct_fill_var(arg, time, philos[i], i))
			return (mutex_destroy(philos, i));
		philos_struct_fill_func(philos[i]);
		i++;
	}
	return (0);
}