/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:22:25 by root              #+#    #+#             */
/*   Updated: 2021/07/04 01:08:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philos_init(t_arguments *arg, t_philo**philos, struct timeval *time)
{
	if (philos_create(arg, philos))
		return (ERROR);
	if (philos_struct_fill(arg, philos, time))
		return (ERROR);
	philos_struct_compound(arg, philos);
	return (0);
}

int	arg_init(char **argv, t_arguments *arg)
{
	arg->num_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	return (ft_isvalidarg(arg));
}

int	prj_philosophers_init(char **argv, t_philo **philo, t_arguments *arg, struct timeval *time)
{
	if (arg_init(argv, arg))
		return (ERROR);
	if (philos_init(arg, philo, time))
		return (ERROR);
	return (0);
}