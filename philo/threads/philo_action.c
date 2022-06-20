/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:00:37 by root              #+#    #+#             */
/*   Updated: 2021/07/17 14:58:08 by larlena          ###   ########.fr       */
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
	return (!(*philo->is_finished == philo->arg->num_of_philo)
		&& end_of_philo_is_die(philo));
}

void	*philo_action_waiter(void *argument)
{
	t_philo	*philo;

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
		{
			if (*philo->is_finished == philo->arg->num_of_philo)
				NULL ;
			else
				print_message_die(philo);
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
	while (philo->end_of_philo(philo))
	{
		philo->philo_eat(philo);
		philo->philo_think(philo);
		philo->philo_sleep(philo);
	}
	return (NULL);
}
