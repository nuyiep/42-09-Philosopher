/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:22 by plau              #+#    #+#             */
/*   Updated: 2023/02/06 20:31:16 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

/* Main struct storing av */
typedef struct s_prg
{
	int			n_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat;
}	t_prg;

typedef	struct s_action
{
	int				id;
	int				fork;
	int				start_time;
	int				last_meal;
	pthread_t		*thread_id;
	pthread_mutex_t	main_lock;
	pthread_mutex_t	check_status;
	pthread_mutex_t	write_data;
	
	pthread_mutex_t	*forks;
	pthread_mutex_t	*eat_check;
	pthread_mutex_t	*death_check;
	pthread_mutex_t	*l_hand;
	pthread_mutex_t *r_hand;
} p_action;

/* Initialization */
void	int_struct(t_prg *args, int ac, char **av);
void	int_struct2(p_action *action);

/* Philosophers */
int		force_death(t_prg *prg, p_action *action);
void	*philo_action(void	*arg);

/* Threads and mutexes */
void	create_philos(t_prg *prg, p_action *action);

/* Helper function */
int		print_error(char *str);
int		error_check(t_prg *prg, int ac, char **av);
int		is_digit(char *str);
int		ft_atoi(char *str);
void	print_timestamp(t_prg *prg, p_action *action, char *msg);
int		gettime(void);

#endif