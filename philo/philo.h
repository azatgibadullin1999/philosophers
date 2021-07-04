/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:12:26 by root              #+#    #+#             */
/*   Updated: 2021/07/05 00:10:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

# define ERROR -1

typedef struct s_arguments
{
	long	num_of_philo;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
}			t_arguments;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eating;
	pthread_t		thread;
	t_arguments		*arg;
	struct timeval	*start_time;
	struct timeval	cycle_time;
	pthread_mutex_t	mutex;
	void			(*philo_eat)(struct s_philo*);
	void			(*philo_sleep)(struct s_philo*);
	void			(*philo_think)(struct s_philo*);
	struct s_philo	*next;
}					t_philo;

//			philo_utils.c
unsigned long	ft_get_elapsed_time_ms(struct timeval *start_time);
int				ft_iseven(int id);
int				ft_isvalidarg(t_arguments *arg);
int				ft_atoi(const char *str);

//			philo_create_pthreads.c
int				philo_pthreads(t_philo*philo);

//			philo_action.c
void			*philo_action_watcher(void *argument);
void			*philo_action(void *argument);

//			action.c
void			philo_sleep(t_philo *philo);
void			philo_eat_even(t_philo *philo);
void			philo_eat_odd(t_philo *philo);
void			philo_think(t_philo *philo);


//			philo_init.c
int				prj_philosophers_init(char **argv, t_philo **philo, t_arguments *arg,  struct timeval *time);
int				arg_init(char **argv, t_arguments *arg);
int				philos_init(t_arguments *arg, t_philo **philos, struct timeval *time);

//			philo_create.c
int				philos_destroy(t_philo **philos, size_t	philos_num);
int				philos_create(t_arguments *arg, t_philo**philos);

//			philo_struct_compound.c
void			philos_struct_compound(t_arguments *arg, t_philo**philos);

//			philo_struct_fill.c
int				philos_struct_fill(t_arguments *arg, t_philo **philos, struct timeval *time);
int				philos_struct_fill_var(t_arguments *arg, struct timeval *time, t_philo *philo, size_t i);
int				philos_struct_fill_func(t_philo *philo);
int				mutex_destroy(t_philo **philos, size_t mutex_num);

#endif