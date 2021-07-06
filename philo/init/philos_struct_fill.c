/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_struct_fill.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:13 by root              #+#    #+#             */
/*   Updated: 2021/07/06 19:20:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	mutex_destroy(t_philo **philos, size_t mutex_num)
{
	size_t	i;

	i = 0;
	pthread_mutex_destroy((*philos)->mutex_of_dead);
	pthread_mutex_destroy((*philos)->mutex_of_message);
	while (i < mutex_num)
	{
		pthread_mutex_destroy(&philos[i]->mutex_of_fork);
		i++;
	}
	return (ERROR);
}

int	philos_struct_fill_func(t_philo *philo)
{
	if (philo->id % 2)
		philo->philo_eat = philo_eat_even;
	else
		philo->philo_eat = philo_eat_odd;
	philo->philo_sleep = philo_sleep;
	philo->philo_think = philo_think;
	return (0);
}

int	philos_struct_fill_var(t_philo *philo, t_common_structs *init, size_t i)
{
	philo->eating = 0;
	philo->id = i + 1;
	philo->arg = init->arg;
	philo->is_dead = init->is_dead;
	philo->start_time = init->start_time;
	philo->mutex_of_dead = init->mutex_of_dead;
	philo->mutex_of_message = init->mutex_of_message;
	philo->cycle_is_start = 0;
	if (pthread_mutex_init(&philo->mutex_of_fork, NULL))
		return (ERROR);
	return (0);
}

int	philos_struct_fill(t_philo **philos, t_common_structs *init)
{
	size_t	i;

	i = 0;
	*init->is_dead = 0;
	if (pthread_mutex_init(init->mutex_of_message, NULL))
		return (ERROR);
	if (pthread_mutex_init(init->mutex_of_dead, NULL))
		return (ERROR);
	while (i < (size_t) init->arg->num_of_philo)
	{
		if (philos_struct_fill_var(philos[i], init, i))
			return (mutex_destroy(philos, i));
		philos_struct_fill_func(philos[i]);
		i++;
	}
	return (0);
}
