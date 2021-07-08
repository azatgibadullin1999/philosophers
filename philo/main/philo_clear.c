/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:18:28 by larlena           #+#    #+#             */
/*   Updated: 2021/07/07 11:57:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philosophers_clear(t_philo *philo)
{
	t_philo	*tmp;

	free(philo->arg);
	free(philo->is_dead);
	free(philo->start_time);
	pthread_mutex_destroy(philo->mutex_of_dead);
	pthread_mutex_destroy(philo->mutex_of_message);
	free(philo->mutex_of_dead);
	free(philo->mutex_of_message);
	philo = philo->next;
	while (philo->id != 1)
	{
		pthread_mutex_destroy(&philo->mutex_of_fork);
		tmp = philo->next;
		free(philo);
		philo = tmp;
	}
	pthread_mutex_destroy(&philo->mutex_of_fork);
	free(philo);
}
