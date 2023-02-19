/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:52 by plau              #+#    #+#             */
/*   Updated: 2023/02/19 15:18:41 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Microsecond */
int	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + time.tv_usec);
}

int	current_time(t_prg *prg)
{
	int	time;

	time = gettime() - prg->start_time;
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
	printf("%d	%d %s\n", current_time(prg) / 1000, i, msg);
	pthread_mutex_unlock(&prg->action->write_mutex);
	return (0);
}

/* Mutex init needs to be followed by mutex destroy or detach */
void	free_destroy(t_prg *prg)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&prg->action->philo_mutex);
	pthread_mutex_destroy(&prg->action->write_mutex);
	pthread_mutex_destroy(&prg->action->start_mutex);
	pthread_mutex_destroy(&prg->action->dead_mutex);
	while (i < prg->n_philo)
	{
		pthread_mutex_destroy(&prg->fork[i].fork_mutex);
		i++;
	}
	free(prg->action->left);
	free(prg->action->right);
	free(prg->fork);
	free(prg->action);
	free(prg);
}

/* To ensure that all philo start at the same time */
int	wait_start(t_action *action)
{
	pthread_mutex_lock(&(action->start_mutex));
	if (action->prg->start == 1)
	{
		pthread_mutex_unlock(&(action->start_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(action->start_mutex));
	return (0);
}
