/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:22:25 by root              #+#    #+#             */
/*   Updated: 2021/07/06 15:44:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*philos_init(t_philo **philos, t_common_structs *init)
{
	t_philo	*dst;

	philos = malloc(sizeof(t_philo *) * init->arg->num_of_philo);
	if (!philos)
		return (NULL);
	if (philos_create(philos, init))
		return (NULL);
	if (philos_struct_fill(philos, init))
		return (NULL);
	philos_struct_compound(philos, init);
	dst = *philos;
	free(philos);
	return (dst);
}

int	arg_init(char **argv, t_arguments *arg)
{
	arg->num_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	return (ft_isvalidarg(arg));
}

int	ft_was_allocated(t_common_structs *init)
{
	return (!init->arg
		|| !init->is_dead
		|| !init->start_time
		|| !init->mutex_of_dead
		|| !init->mutex_of_message);
}

int	common_struct_init(t_common_structs *init)
{
	init->arg = malloc(sizeof(t_arguments));
	init->is_dead = malloc(sizeof(int));
	init->start_time = malloc(sizeof(struct timeval));
	init->mutex_of_dead = malloc(sizeof(pthread_mutex_t));
	init->mutex_of_message = malloc(sizeof(pthread_mutex_t));
	return (ft_was_allocated(init));
}

int	prj_philosophers_init(char **argv, t_philo **philo, t_common_structs *init)
{
	if (common_struct_init(init))
		return (ERROR);
	if (arg_init(argv, init->arg))
		return (ERROR);
	*philo = philos_init(philo, init);
	if (!*philo)
		return (ERROR);
	return (0);
}
