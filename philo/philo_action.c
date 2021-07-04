/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:00:37 by root              #+#    #+#             */
/*   Updated: 2021/07/04 23:13:36 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_action_watcher(void *argument)
{
	t_philo *philo;

	philo = (t_philo *)argument;
	while (1)
	{
		if (!philo->eating && (ft_get_elapsed_time_ms(&philo->cycle_time) > (unsigned long) philo->arg->time_to_die))
		{
			printf("%lu ms %d \x1b[31mis dead\x1b[0m\n", ft_get_elapsed_time_ms(philo->start_time), philo->id);
			exit(0);
		}
	}
}

void	*philo_action(void *argument)
{
	t_philo	*philo;

	philo = (t_philo *)argument;
	gettimeofday(&philo->cycle_time, NULL);
	while (1)
	{
		philo->philo_eat(philo);
		philo->philo_think(philo);
		philo->philo_sleep(philo);
	}
	return (NULL);
}