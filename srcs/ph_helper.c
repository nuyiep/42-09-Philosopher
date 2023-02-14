/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:52 by plau              #+#    #+#             */
/*   Updated: 2023/02/14 16:54:11 by plau             ###   ########.fr       */
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

/* Milisecond */
int	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	current_time(t_prg *prg)
{
	int	time;

	time = gettime() - prg->action->start_time;
	return (time);
}

/* Print message in the format- [timestamp] [id] [msg] */
int	print_timestamp(t_prg *prg, char *msg, int i)
{
	pthread_mutex_lock(&prg->action->write_mutex);
	if (prg->finish == 1)
	{
		pthread_mutex_unlock(&prg->action->write_mutex);
		return (1);
	}
	printf("%d	%d %s\n", current_time(prg), i, msg);
	pthread_mutex_unlock(&prg->action->write_mutex);
	return (0);
}

/* Mutex init needs to be followed by mutex destroy or detach */
void	free_destroy(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_destroy(&prg->fork[i].fork_mutex);
		pthread_mutex_destroy(&prg->action[i].philo_mutex);
		pthread_mutex_destroy(&prg->action[i].write_mutex);
		i++;
	}
	free(prg->action->left);
	free(prg->action->right);
	free(prg);
}
