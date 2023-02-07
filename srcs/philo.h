/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:22 by plau              #+#    #+#             */
/*   Updated: 2023/02/07 21:12:47 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_fork
{
	int				n;
	pthread_mutex_t	fork_mutex;
}	t_fork;

typedef	struct s_action
{
	int				id;
	int				fork;
	int				start_time;
	int				last_meal;
	int				eat_check;
	pthread_mutex_t	philo_mutex;
	pthread_mutex_t	check_status;
	pthread_mutex_t	write_mutex;
	
	t_fork			*left;
	t_fork			*right;	
} p_action;

/* Main struct storing av */
typedef struct s_prg
{
	int			n_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
	p_action	*action;
}	t_prg;

/* Initialization */
t_prg	*int_struct(t_prg *prg, int ac, char **av);
void	init_fork(t_prg *prg);
void	create_philos(t_prg *prg);

/* Philosophers */
int		force_death(t_prg *prg);
void	*philo_action(void	*arg);

/* Helper function */
int		print_error(char *str);
int		error_check(int ac, char **av);
int		is_digit(char *str);
int		ft_atoi(char *str);
void	print_timestamp(t_prg *prg, char *msg);
int		gettime(void);
void	free_destroy(t_prg *prg);

#endif