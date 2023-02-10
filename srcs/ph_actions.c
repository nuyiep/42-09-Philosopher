/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/10 15:10:32 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philoeat(t_prg *prg)
{
	pthread_mutex_lock(&prg->action->philo_mutex);
	print_timestamp(prg, "is eating", prg->action->id);
	prg->action->last_meal = gettime();
	usleep(prg->time_to_eat);
	pthread_mutex_unlock(&prg->action->philo_mutex);
}

void	philosleep_then_think(t_prg *prg)
{
	print_timestamp(prg, "is sleeping", prg->action->id);
	usleep(prg->time_to_sleep);
	print_timestamp(prg, "is thinking", prg->action->id);
}

void	grab_fork(t_action *action)
{
	pthread_mutex_lock(&(action->left->fork_mutex));
	print_timestamp(action->prg, "has taken a fork", action->id);
	action->fork++;
	pthread_mutex_lock(&(action->right->fork_mutex));
	print_timestamp(action->prg, "has taken a fork", action->id);
	action->fork++;
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
	while (1)
	{
		if (action->fork == 0)
			grab_fork(action);
		else if (action->fork == 2)
		{
			philoeat(action->prg);
			down_fork(action);
			philosleep_then_think(action->prg);
			action->fork = 0;
		}
	}
	return (NULL);
}
