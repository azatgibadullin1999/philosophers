/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:08 by root              #+#    #+#             */
/*   Updated: 2021/07/05 15:22:23 by larlena          ###   ########.fr       */
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

int	philos_create(t_philo **philos, t_common_structs *init)
{
	size_t	i;

	i = 0;
	while (i < (size_t)init->arg->num_of_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (philos_destroy(philos, i));
		i++;
	}
	return (0);
}
