/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:22 by plau              #+#    #+#             */
/*   Updated: 2023/02/20 14:16:40 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

struct	s_prg;

enum e_bool
{
	false,
	true
};

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
}	t_fork;

/* Philo mutex- finish */
/* Write mutex- print stamp */
/* Start mutex- start */

/* Eat mutex- eat check */
/* Death mutex- last meal */
typedef struct s_action
{
	int				id;
	int				fork;
	int				last_meal;
	int				eat_check;
	int				ph_ate;
	t_fork			*left;
	t_fork			*right;
	struct s_prg	*prg;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	death_mutex;
	pthread_t		temp;
	pthread_t		monitor;
}	t_action;

/* Main struct storing av */
typedef struct s_prg
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				finish;
	int				start;
	int				start_time;
	t_action		*action;
	t_fork			*fork;
	pthread_mutex_t	start_mutex;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	write_mutex;
}	t_prg;

/* Initialization */
void			int_struct(t_prg *prg, int ac, char **av);
void			init_fork(t_prg *prg);
void			create_philos(t_prg *prg);

/* Philosophers */
void			*philo_action(void	*arg);
int				ph_action(t_action *action);

/* Helper function */
int				print_error(char *str);
int				error_check(int ac, char **av);
int				is_digit(char *str);
int				ft_atoi(char *str);
int				print_timestamp(t_prg *prg, char *msg, int i);
int				gettime(void);
int				current_time(t_prg *prg);
void			free_destroy(t_prg *prg);
void			ft_usleep(int time);
int				wait_start(t_action *action);

/* Checker */
int				check_if_all_ate(t_prg *prg);
void			*check_if_dead(void *action_in);
int				check_status(t_action *action);

#endif