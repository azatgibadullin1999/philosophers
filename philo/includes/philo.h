/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:12:26 by root              #+#    #+#             */
/*   Updated: 2021/07/09 20:44:10 by root             ###   ########.fr       */
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
	long	num_of_eat;
}			t_arguments;

typedef struct s_common_structs
{
	int				*is_dead;
	volatile int	*is_finished;
	t_arguments		*arg;
	struct timeval	*start_time;
	pthread_mutex_t	*mutex_of_dead;
	pthread_mutex_t	*mutex_of_message;
	pthread_mutex_t	*mutex_of_check_condition;
}					t_common_structs;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eating;
	int				cycle_is_start;
	struct timeval	cycle_time;
	pthread_t		thread_philo;
	pthread_t		thread_watcher;
	pthread_mutex_t	mutex_of_fork;
	long			num_of_eat;
	t_arguments		*arg;
	struct timeval	*start_time;
	pthread_mutex_t	*mutex_of_check_condition;
	pthread_mutex_t	*mutex_of_message;
	pthread_mutex_t	*mutex_of_dead;
	volatile int	*is_finished;
	int				*is_dead;
	int				(*end_of_philo)(struct s_philo*);
	void			(*philo_eat)(struct s_philo*);
	void			(*philo_sleep)(struct s_philo*);
	void			(*philo_think)(struct s_philo*);
	struct s_philo	*next;
}					t_philo;

int				end_of_philo_is_time(t_philo *philo);
int				end_of_philo_is_die(t_philo *philo);

//			philo_utils.c
unsigned long	ft_get_elapsed_time_ms(struct timeval *start_time);
int				ft_iseven(int id);
int				ft_isvalidarg(t_arguments *arg);
int				ft_atoi(const char *str);
int				ft_is_dead(t_philo *philo);
void			philosophers_clear(t_philo *philo);

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
void			my_usleep(unsigned long time);

//			massage.c
void			print_message_take_fork(t_philo *philo);
void			print_message_sleep(t_philo *philo);
void			print_message_think(t_philo *philo);
void			print_message_eat(t_philo *philo);
void			print_message_die(t_philo *philo);

//			philo_init.c
int				arg_init(int argc, char **argv, t_arguments *arg);
t_philo			*philos_init(t_philo **philos, t_common_structs *init);
int				prj_philosophers_init(int argc, char **argv,
					t_philo **philo, t_common_structs *init);

//			philo_create.c
int				philos_destroy(t_philo **philos, size_t	philos_num);
int				philos_create(t_philo **philos, t_common_structs *init);

//			philo_struct_compound.c
void			philos_struct_compound(t_philo **philos,
					t_common_structs *init);

//			philo_struct_fill.c
int				philos_struct_fill(t_philo **philos, t_common_structs *init);
int				philos_struct_fill_func(t_philo *philo);
int				mutex_destroy(t_philo **philos, size_t mutex_num);
int				philos_struct_fill_var(t_philo *philo,
					t_common_structs *init, size_t i);

#endif