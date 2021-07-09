/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:00:37 by root              #+#    #+#             */
/*   Updated: 2021/07/09 20:47:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	end_of_philo_is_die(t_philo *philo)
{
	return (!*philo->is_dead);
}

int	end_of_philo_is_time(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_check_condition);
	if (philo->num_of_eat == philo->arg->num_of_eat)
		*philo->is_finished += 1;
	pthread_mutex_unlock(philo->mutex_of_check_condition);
	return (!(*philo->is_finished == philo->arg->num_of_philo) && end_of_philo_is_die(philo));
}

void	*philo_action_waiter(void *argument)
{
	t_philo *philo;

	philo = (t_philo *) argument;
	while (1)
	{
		philo = philo->next;
	}
}

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
	while (philo->end_of_philo(philo))
	{
		philo->philo_eat(philo);
		philo->philo_think(philo);
		philo->philo_sleep(philo);
	}
	return (NULL);
}
