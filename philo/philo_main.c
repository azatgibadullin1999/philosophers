/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:11:28 by root              #+#    #+#             */
/*   Updated: 2021/07/06 14:44:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_common_structs	init;
	t_philo				*philo;

	if (argc != 5)
		return (ERROR);
	if (prj_philosophers_init(argv, &philo, &init))
		return (ERROR);
	philo_pthreads(philo);
	return (0);
}
