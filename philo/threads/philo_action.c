/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:00:37 by root              #+#    #+#             */
/*   Updated: 2021/07/07 11:56:22 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philo_action_watcher(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	while (1)
	{
		pthread_mutex_lock(philo->mutex_of_dead);
		if (!*philo->is_dead && philo->cycle_is_start && ft_is_dead(philo))
			break ;
		pthread_mutex_unlock(philo->mutex_of_dead);
	}
	print_message_die(philo);
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
