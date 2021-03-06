/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:30:23 by root              #+#    #+#             */
/*   Updated: 2021/07/08 23:56:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_sleep(t_philo *philo)
{
	print_message_sleep(philo);
	my_usleep(philo->arg->time_to_sleep * 1000);
}

void	philo_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_of_fork);
	print_message_take_fork(philo);
	pthread_mutex_lock(&philo->next->mutex_of_fork);
	print_message_take_fork(philo);
	philo->eating = 1;
	philo->num_of_eat++;
	print_message_eat(philo);
	gettimeofday(&philo->cycle_time, NULL);
	my_usleep(philo->arg->time_to_eat * 1000);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->mutex_of_fork);
	pthread_mutex_unlock(&philo->next->mutex_of_fork);
}

void	philo_eat_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->next->mutex_of_fork);
	print_message_take_fork(philo);
	pthread_mutex_lock(&philo->mutex_of_fork);
	print_message_take_fork(philo);
	philo->eating = 1;
	philo->num_of_eat++;
	print_message_eat(philo);
	gettimeofday(&philo->cycle_time, NULL);
	my_usleep(philo->arg->time_to_eat * 1000);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->next->mutex_of_fork);
	pthread_mutex_unlock(&philo->mutex_of_fork);
}

void	philo_think(t_philo *philo)
{
	print_message_think(philo);
}
