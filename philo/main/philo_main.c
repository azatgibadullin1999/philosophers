/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:11:28 by root              #+#    #+#             */
/*   Updated: 2021/07/09 21:07:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_common_structs	init;
	t_philo				*philo;

	if (argc < 5 || argc > 6)
		return (ERROR);
	if (prj_philosophers_init(argc, argv, &philo, &init))
		return (ERROR);
	philo_pthreads(philo);
	philosophers_clear(philo);
	return (0);
}
