/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/20 15:40:39 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philoeat(t_action *action)
{
	if (print_timestamp(action->prg, "is eating", action->id) == 1)
		return (1);
	pthread_mutex_lock(&action->eat_mutex);
	action->last_meal = current_time(action->prg);
	pthread_mutex_unlock(&action->eat_mutex);
	pthread_mutex_lock(&(action->eat_mutex));
	action->eat_check++;
	pthread_mutex_unlock(&(action->eat_mutex));
	ft_usleep(action->prg->time_to_eat);
	return (0);
}

int	philosleep_then_think(t_action *action)
{
	if (print_timestamp(action->prg, "is sleeping", action->id) == 1)
		return (1);
	ft_usleep(action->prg->time_to_sleep);
	if (print_timestamp(action->prg, "is thinking", action->id) == 1)
		return (1);
	return (0);
}

int	grab_fork(t_action *action)
{
	pthread_mutex_lock(&(action->left->fork_mutex));
	if (print_timestamp(action->prg, "has taken a fork", action->id) == 1)
	{
		pthread_mutex_unlock(&(action->left->fork_mutex));
		return (1);
	}
	action->fork++;
	if (action->prg->n_philo != 1)
	{
		pthread_mutex_lock(&(action->right->fork_mutex));
		if (print_timestamp(action->prg, "has taken a fork", action->id) == 1)
		{
			pthread_mutex_unlock(&(action->right->fork_mutex));
			return (1);
		}
		action->fork++;
	}
	return (0);
}

void	down_fork(t_action *action)
{
	pthread_mutex_unlock(&(action->left->fork_mutex));
	action->fork--;
	pthread_mutex_unlock(&(action->right->fork_mutex));
	action->fork--;
}

/* Philosopher's actions */
int	ph_action(t_action *action)
{
	if (action->fork == 0)
	{
		if (grab_fork(action) == 1)
		{
			down_fork(action);
			return (1);
		}
	}
	else if (action->fork == 2)
	{
		if (philoeat(action) == 1)
		{
			down_fork(action);
			return (1);
		}
		down_fork(action);
		if (philosleep_then_think(action) == 1)
			return (1);
		action->fork = 0;
	}
	return (0);
}
