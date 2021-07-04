/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_struct_compound.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:11 by root              #+#    #+#             */
/*   Updated: 2021/07/04 23:57:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philos_struct_compound(t_arguments *arg, t_philo **philos)
{
	size_t	i;

	i = 0;
	while (i < (size_t) arg->num_of_philo - 1)
	{
		philos[i]->next = philos[i + 1];
		i++;
	}
	philos[i]->next = philos[0];
}