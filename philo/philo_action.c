/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:00:37 by root              #+#    #+#             */
/*   Updated: 2021/07/06 14:21:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action_watcher(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while (!*philo->is_dead)
	{
		usleep(20);
		pthread_mutex_lock(philo->mutex_of_dead);
		if (!*philo->is_dead && philo->cycle_is_start && ft_is_dead(philo))
		{
			*philo->is_dead = 1;
			break ;
		}
		pthread_mutex_unlock(philo->mutex_of_dead);
	}
	return (NULL);
}

void	*philo_action(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	gettimeofday(&philo->cycle_time, NULL);
	philo->cycle_is_start = 1;
	while (!*philo->is_dead)
	{
		philo->philo_eat(philo);
		philo->philo_think(philo);
		philo->philo_sleep(philo);
	}
	return (NULL);
}
