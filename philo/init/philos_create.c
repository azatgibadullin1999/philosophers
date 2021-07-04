/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:08 by root              #+#    #+#             */
/*   Updated: 2021/07/04 23:57:16 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philos_destroy(t_philo **philos, size_t	philos_num)
{
	size_t	i;

	i = 0;
	while (i < philos_num)
	{
		free(philos[i]);
		i++;
	}
	return (ERROR);
}

int	philos_create(t_arguments *arg, t_philo **philos)
{
	size_t	i;

	i = 0;
	while (i < (size_t) arg->num_of_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return(philos_destroy(philos, i));
		i++;
	}
	return (0);
}