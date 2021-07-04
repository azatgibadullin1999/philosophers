/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 16:30:23 by root              #+#    #+#             */
/*   Updated: 2021/07/04 01:03:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	printf("%lu ms %d \x1b[30mis sleeping\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
	usleep(philo->arg->time_to_sleep * 1000);
}

void	philo_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%lu ms %d \x1b[36mhas taken a fork\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
	pthread_mutex_lock(&philo->next->mutex);

	philo->eating = 1;
	printf("%lu ms %d \x1b[32mis eating eating\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
	usleep(philo->arg->time_to_eat * 1000);
	gettimeofday(&philo->cycle_time, NULL);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(&philo->next->mutex);
}

void	philo_eat_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->next->mutex);
	printf("%lu ms %d \x1b[36mhas taken a fork\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
	pthread_mutex_lock(&philo->mutex);

	philo->eating = 1;
	printf("%lu ms %d \x1b[32mis eating eating\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
	usleep(philo->arg->time_to_eat * 1000);
	gettimeofday(&philo->cycle_time, NULL);
	pthread_mutex_unlock(&philo->next->mutex);
	pthread_mutex_unlock(&philo->mutex);
	philo->eating = 0;
}

void	philo_think(t_philo *philo)
{
	printf("%lu ms %d \x1b[35mis thinking\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
}