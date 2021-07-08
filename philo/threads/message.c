/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:31:51 by larlena           #+#    #+#             */
/*   Updated: 2021/07/06 21:07:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_message_take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	if (!*philo->is_dead)
	{
		printf("%lu ms %d \x1b[36mhas taken a fork\x1b[0m\n",
			ft_get_elapsed_time_ms(philo->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	if (!*philo->is_dead)
	{
		printf("%lu ms %d \x1b[30mis sleeping\x1b[0m\n",
			ft_get_elapsed_time_ms(philo->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_think(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	if (!*philo->is_dead)
	{
		printf("%lu ms %d \x1b[35mis thinking\x1b[0m\n",
			ft_get_elapsed_time_ms(philo->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	if (!*philo->is_dead)
	{
		printf("%lu ms %d \x1b[32mis eating\x1b[0m\n",
			ft_get_elapsed_time_ms(philo->start_time),
			philo->id);
	}
	pthread_mutex_unlock(philo->mutex_of_message);
}

void	print_message_die(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_of_message);
	if (!*philo->is_dead)
	{
		printf("%lu ms %d \x1b[31mis dead\x1b[0m\n",
			ft_get_elapsed_time_ms(philo->start_time),
			philo->id);
		*philo->is_dead = 1;
	}
	pthread_mutex_unlock(philo->mutex_of_message);
}
