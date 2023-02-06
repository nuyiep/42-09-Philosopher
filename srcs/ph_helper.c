/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:52 by plau              #+#    #+#             */
/*   Updated: 2023/02/06 20:08:38 by plau             ###   ########.fr       */
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
int	error_check(t_prg *prg, int ac, char **av)
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
			return (print_error("Invalid arguments- Not digits"));
		i++;
	}
	return (0);
	(void)prg;
}

/* Get time */
int	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

/* Print message in the format- [timestamp] [id] [msg] */
void	print_timestamp(t_prg *prg, p_action *action, char *msg)
{
	int		start;
	int		time;

	time = (gettime() - action->start_time) / 1000;
	pthread_mutex_lock(&action->check_status);
	start = action->start_time;
	pthread_mutex_unlock(&action->check_status);
	pthread_mutex_lock(&action->write_data);
	if (start)
		printf("%d %d %s", time, action->id, msg);
	pthread_mutex_unlock(&action->write_data);
	(void)prg;
}

/* Mutex init needs to be followed by mutex destroy */
void	free_destroy(t_prg *prg, p_action *action)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&action->main_lock);
	while (i < prg->n_philo)
		pthread_mutex_destroy(&action->forks[i++]);
}
