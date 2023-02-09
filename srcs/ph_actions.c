/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/09 13:46:46 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philoeat(t_prg *prg)
{
	print_timestamp(prg, "is eating\n");
	pthread_mutex_lock(&prg->action->philo_mutex);
	prg->action->last_meal = gettime();
	pthread_mutex_unlock(&prg->action->philo_mutex);
	usleep(prg->time_to_eat);
	pthread_mutex_lock(&prg->action->philo_mutex);
	if (prg->must_eat > 0)
		prg->must_eat--;
	pthread_mutex_unlock(&prg->action->philo_mutex);
}

void	philosleep_then_think(t_prg *prg)
{
	print_timestamp(prg, "is sleeping\n");
	usleep(prg->time_to_sleep);
	print_timestamp(prg, "is thinking\n");
}

void	grab_fork(p_action *action)
{
	printf("%d:", action->id);
	printf("enter grab fork\n");
	pthread_mutex_lock(&(action->left->fork_mutex));
	print_timestamp(action->prg, "has taken a fork\n");
	action->fork++;
	pthread_mutex_lock(&(action->right->fork_mutex));
	print_timestamp(action->prg, "has taken a fork\n");
	action->fork++;
}

void	down_fork(t_fork *left, t_fork *right)
{
	pthread_mutex_unlock(&(left->fork_mutex));
	pthread_mutex_unlock(&(right->fork_mutex));
}

/* Each philo will need to eat before sleep */
/* When he wakes up, he will do some thinking before eating again */
void	*philo_action(void	*action_in)
{
	p_action	*action;
	
	action = (p_action *)action_in;
	if (action->id % 2 == 0)
		usleep(2500);
	while ((check_if_dead(action) == 0)) //&& (check_if_(action) == 0))
	{
		printf("%d\n", action->fork);
		if (action->fork == 0)
			grab_fork(action);
		else if (action->fork == 2)
		{
			philoeat(action->prg);
			down_fork(action->left, action->right);
			philosleep_then_think(action->prg);
			action->fork = 0;
		}
	}
	printf("Here\n");
	return (NULL);
}
