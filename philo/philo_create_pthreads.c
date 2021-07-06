/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_pthreads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:35:46 by root              #+#    #+#             */
/*   Updated: 2021/07/06 14:43:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_pthreads(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < (size_t) philo->arg->num_of_philo)
	{
		pthread_create(&philo->thread_philo,
			NULL,
			philo_action,
			(void *)philo);
		pthread_create(&philo->thread_watcher,
			NULL,
			philo_action_watcher,
			(void *)philo);
		philo = philo->next;
		i++;
	}
	return (0);
}

static int	wait_pthreads(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < (size_t) philo->arg->num_of_philo)
	{
		usleep(20);
		if (*philo->is_dead)
		{
			pthread_detach(philo->thread_philo);
			philo = philo->next;
			i++;
		}
	}
	print_message_die(philo);
	return (0);
}

int	philo_pthreads(t_philo *philo)
{
	gettimeofday(philo->start_time, NULL);
	create_pthreads(philo);
	wait_pthreads(philo);
	return (0);
}
