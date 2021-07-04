/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:11:28 by root              #+#    #+#             */
/*   Updated: 2021/07/03 14:25:11 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	struct timeval	time;
	t_philo			*philo;
	t_arguments		arg;
	
	if (argc != 5)
		return (ERROR);
	if (prj_philosophers_init(argv, &philo, &arg, &time))
		return (ERROR);
	philo_pthreads(philo);
	return (0);
}
