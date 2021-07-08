/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:56:44 by root              #+#    #+#             */
/*   Updated: 2021/07/08 14:39:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_iseven(int id)
{
	return (id % 2);
}

int	ft_isvalidarg(t_arguments *arg)
{
	return (arg->num_of_philo <= 0
		|| arg->time_to_die <= 0
		|| arg->time_to_eat <= 0
		|| arg->time_to_sleep <= 0);
}

unsigned long	ft_get_elapsed_time_ms(struct timeval *start_time)
{
	struct timeval	present_time;
	unsigned long	dst;

	gettimeofday(&present_time, NULL);
	dst = ((present_time.tv_sec * 1000) + (present_time.tv_usec / 1000))
		- ((start_time->tv_sec * 1000) + (start_time->tv_usec / 1000));
	return (dst);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	dst;

	i = 0;
	dst = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		dst = dst * 10 + str[i] - '0';
		i++;
	}
	return (dst * sign);
}

int	ft_is_dead(t_philo *philo)
{
	return (!philo->eating
		&& ((ft_get_elapsed_time_ms(&philo->cycle_time))
			> (unsigned long) philo->arg->time_to_die + 1));
}
