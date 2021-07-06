/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_struct_compound.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:52:11 by root              #+#    #+#             */
/*   Updated: 2021/07/05 15:23:34 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philos_struct_compound(t_philo **philos, t_common_structs *init)
{
	size_t	i;

	i = 0;
	while (i < (size_t) init->arg->num_of_philo - 1)
	{
		philos[i]->next = philos[i + 1];
		i++;
	}
	philos[i]->next = philos[0];
}
