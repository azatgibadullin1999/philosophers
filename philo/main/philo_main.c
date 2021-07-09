/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:11:28 by root              #+#    #+#             */
/*   Updated: 2021/07/09 00:00:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_common_structs	init;
	t_philo				*philo;

	// if (argc != 5)
		// return (ERROR);
	if (prj_philosophers_init(argc, argv, &philo, &init))
		return (ERROR);
	philo_pthreads(philo);
	philosophers_clear(philo);
	return (0);
}
