/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/15 21:25:37 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philoeat(t_action *action)
{
	pthread_mutex_lock(&(action->philo_mutex));
	if (print_timestamp(action->prg, "is eating", action->id) == 1)
	{
		pthread_mutex_unlock(&(action->philo_mutex));
		return (1);	
	}
	action->last_meal = current_time(action->prg);
	usleep(action->prg->time_to_eat);
	action->eat_check++;
	pthread_mutex_unlock(&action->philo_mutex);
	return (0);
}

int	philosleep_then_think(t_action *action)
{
	if (print_timestamp(action->prg, "is sleeping", action->id) == 1)
		return (1);
	usleep(action->prg->time_to_sleep);
	if (print_timestamp(action->prg, "is thinking", action->id) == 1)
		return (1);
	return (0);
}

int	grab_fork(t_action *action)
{
	pthread_mutex_lock(&(action->left->fork_mutex));
	if (print_timestamp(action->prg, "has taken a fork", action->id) == 1)
		return (1);
	action->fork++;
	if (action->prg->n_philo != 1)
	{
		pthread_mutex_lock(&(action->right->fork_mutex));
		if (print_timestamp(action->prg, "has taken a fork", action->id) == 1)
			return (1);
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
		if (check_if_dead(action) == 1)
		{
			action->prg->finish = 1;
			return (NULL);
		}
		if (action->prg->must_eat > 0)
		{
			if (check_if_all_ate(action->prg) == 1)
			{	
				action->prg->finish = 1;
				if (action->eat_check < action->prg->must_eat)
					printf("%d	%d %s\n", current_time(action->prg), action->id, "is eating");
				return (NULL);
			}
		}
		if (action->fork == 0)
		{
			if (grab_fork(action) == 1)
				return (NULL);
		}
		else if (action->fork == 2)
		{
			if (philoeat(action) == 1)
				return (NULL);
			down_fork(action);
			if (philosleep_then_think(action) == 1)
				return (NULL);
			action->fork = 0;
		}
	}
	return (NULL);
}
