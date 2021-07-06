/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:31:51 by larlena           #+#    #+#             */
/*   Updated: 2021/07/06 14:13:56 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	printf("%lu ms %d \x1b[36mhas taken a fork\x1b[0m\n",
		ft_get_elapsed_time_ms(philo->start_time),
		philo->id);
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	printf("%lu ms %d \x1b[30mis sleeping\x1b[0m\n",
		ft_get_elapsed_time_ms(philo->start_time),
		philo->id);
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_think(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	printf("%lu ms %d \x1b[35mis thinking\x1b[0m\n",
		ft_get_elapsed_time_ms(philo->start_time),
		philo->id);
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	printf("%lu ms %d \x1b[32mis eating eating\x1b[0m\n",
		ft_get_elapsed_time_ms(philo->start_time),
		philo->id);
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_die(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	printf("%lu ms %d \x1b[31mis dead\x1b[0m\n",
		ft_get_elapsed_time_ms(philo->start_time),
		philo->id);
	pthread_mutex_unlock(philo->mutex_of_message);
}
