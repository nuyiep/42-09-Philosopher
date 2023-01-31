/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:22 by plau              #+#    #+#             */
/*   Updated: 2023/01/30 17:24:32 by plau             ###   ########.fr       */
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
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times;
}	t_prg;

/* Initialization */
void	int_struct(t_prg *args, int ac, char **av);

/* Threads and mutexes */
void	*routine();
void	init_thread(void);

/* Helper function */
void	error_message(char *str);
int		error_check(t_prg *prg, int ac, char **av);
int		is_digit(char *str);
int		ft_atoi(char *str);

#endif