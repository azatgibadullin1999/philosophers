/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:11:28 by root              #+#    #+#             */
/*   Updated: 2021/07/06 18:16:19 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philosophers_clear(t_philo *philo)
{
	t_philo	*tmp;
	size_t	i;

	i = 0;
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

int	main(int argc, char **argv)
{
	t_common_structs	init;
	t_philo				*philo;

	if (argc != 5)
		return (ERROR);
	if (prj_philosophers_init(argv, &philo, &init))
		return (ERROR);
	philo_pthreads(philo);
	philosophers_clear(philo);
	return (0);
}
