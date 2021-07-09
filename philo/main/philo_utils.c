/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 18:56:44 by root              #+#    #+#             */
/*   Updated: 2021/07/08 23:53:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	my_usleep(unsigned long time)
{
	struct timeval	start_sleep;

	time = time / 1000;
	gettimeofday(&start_sleep, NULL);
	while (ft_get_elapsed_time_ms(&start_sleep) < time)
		usleep(10);
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
	int			sign;
	long long	dst;

	dst = 0;
	sign = 1;
	while (*str == '\t' || *str == '\v' || *str == ' '
		|| *str == '\n' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		dst = dst * 10 + *str - '0';
		str++;
	}
	return (dst * sign);
}

int	ft_is_dead(t_philo *philo)
{
	return (!philo->eating
		&& ((ft_get_elapsed_time_ms(&philo->cycle_time))
			> (unsigned long) philo->arg->time_to_die));
}
