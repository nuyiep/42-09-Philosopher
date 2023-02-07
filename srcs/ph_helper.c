/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:52 by plau              #+#    #+#             */
/*   Updated: 2023/02/07 21:03:47 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Print error message */
int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

/* Return 1 if error */
int	error_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5)
		return (print_error("Less than 5 arguments"));
	if (ac > 6)
		return (print_error("More than 6 arguments"));
	while (i < ac)
	{
		if (is_digit(av[i]) == 0)
			return (print_error("Input must only be numbers"));
		i++;
	}
	return (0);
}

/* Get time */
int	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

/* Print message in the format- [timestamp] [id] [msg] */
void	print_timestamp(t_prg *prg, char *msg)
{
	int		start;
	int		time;

	time = (gettime() - prg->action->start_time) / 1000;
	pthread_mutex_lock(&prg->action->philo_mutex);
	start = prg->action->start_time;
	pthread_mutex_unlock(&prg->action->philo_mutex);
	pthread_mutex_lock(&prg->action->philo_mutex);
	if (start)
		printf("%d %d %s", time, prg->action->id, msg);
	pthread_mutex_unlock(&prg->action->philo_mutex);
	(void)prg;
}

/* Mutex init needs to be followed by mutex destroy or detach */
// void	free_destroy(t_prg *prg)
// {
// 	int	i;

// 	i = 0;
// 	while (i < prg->n_philo)
// 	{
// 		pthread_mutex_destroy(&prg->action->fork);
// 	}
// }
