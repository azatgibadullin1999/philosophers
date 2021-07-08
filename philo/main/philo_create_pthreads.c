/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_pthreads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 19:35:46 by root              #+#    #+#             */
/*   Updated: 2021/07/08 14:39:13 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		pthread_join(philo->thread_philo, NULL);
		philo = philo->next;
		i++;
	}
	return (0);
}

int	philo_pthreads(t_philo *philo)
{
	gettimeofday(philo->start_time, NULL);
	create_pthreads(philo);
	wait_pthreads(philo);
	return (0);
}
