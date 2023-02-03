/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:22 by plau              #+#    #+#             */
/*   Updated: 2023/02/02 19:30:20 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef unsigned char	status;

/* Main struct storing av */
typedef struct s_prg
{
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
}	t_prg;

typedef	struct s_action
{
	int				id;
	int				start_time;
	int				last_meal;
	int				fork;
	status			start_sim;
	status			is_thinking;
	pthread_mutex_t	check_status;
	pthread_mutex_t	write_data;
	
	pthread_mutex_t	*eat_check;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t *r_hand;
} p_action;


/* Initialization */
void	int_struct(t_prg *args, int ac, char **av);

/* Philosophers */
int	force_death(t_prg *prg, p_action *action);

/* Threads and mutexes */
void	routine(void);
void	init_thread(void);

/* Helper function */
int		print_error(char *str);
int		error_check(t_prg *prg, int ac, char **av);
int		is_digit(char *str);
int		ft_atoi(char *str);
void	print_timestamp(t_prg *prg, p_action *action, char *msg);
int		gettime(void);

#endif