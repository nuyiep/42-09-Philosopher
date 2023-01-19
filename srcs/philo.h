/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:25:22 by plau              #+#    #+#             */
/*   Updated: 2023/01/19 19:37:23 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_prg
{
	int	n_philo;
	
}	t_prg;


/* Initialization */
void	int_struct(t_prg *args, int ac, char **av);

/* Threads and mutexes */
void	*routine();
void	init_thread(void);

/* Helper function */
void	error_message(char *str);
int		error_check(int ac, char **av);

#endif