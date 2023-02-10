/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/10 18:51:44 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philoeat(t_action *action)
{
	pthread_mutex_lock(&action->philo_mutex);
	print_timestamp(action->prg, "is eating", action->id);
	action->last_meal = current_time(action->prg);
	usleep(action->prg->time_to_eat);
	pthread_mutex_unlock(&action->philo_mutex);
}

void	philosleep_then_think(t_action *action)
{
	print_timestamp(action->prg, "is sleeping", action->id);
	usleep(action->prg->time_to_sleep);
	print_timestamp(action->prg, "is thinking", action->id);
}

void	grab_fork(t_action *action)
{
	pthread_mutex_lock(&(action->left->fork_mutex));
	print_timestamp(action->prg, "has taken a fork", action->id);
	action->fork++;
	if (action->prg->n_philo != 1)
	{
		pthread_mutex_lock(&(action->right->fork_mutex));
		print_timestamp(action->prg, "has taken a fork", action->id);
		action->fork++;
	}
}

void	down_fork(t_action *action)
{
	pthread_mutex_unlock(&(action->left->fork_mutex));
	action->fork--;
	pthread_mutex_unlock(&(action->right->fork_mutex));
	action->fork--;
}

/* Each philo will need to eat before sleep */
/* When he wakes up, he will do some thinking before eating again */
void	*philo_action(void	*action_in)
{
	t_action	*action;
	
	action = (t_action *)action_in;
	if (action->id % 2 == 0)
		usleep(2500);
	while (check_if_dead(action) == 0)
	{
		if (action->fork == 0)
			grab_fork(action);
		else if (action->fork == 2)
		{
			philoeat(action);
			down_fork(action);
			philosleep_then_think(action);
			action->fork = 0;
		}
	}
	return (NULL);
}
