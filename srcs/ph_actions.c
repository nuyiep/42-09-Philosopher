/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/06 20:26:01 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philoeat(t_prg *prg, p_action *action)
{
	int	index;

	index = action->id - 1;
	print_timestamp(prg, action, "is eating\n");
	pthread_mutex_lock(&action->death_check[index]);
	action->last_meal = gettime();
	pthread_mutex_unlock(&action->death_check[index]);
	usleep(prg->time_to_eat);
	pthread_mutex_lock(&action->eat_check[index]);
	if (prg->must_eat > 0)
		prg->must_eat--;
	pthread_mutex_unlock(&action->eat_check[index]);
}

void	philosleep_then_think(t_prg *prg, p_action *action)
{
	print_timestamp(prg, action, "is sleeping\n");
	usleep(prg->time_to_sleep);
	print_timestamp(prg, action, "is thinking\n");
}

void	grab_fork(t_prg *prg, p_action *action)
{
	pthread_mutex_lock(action->l_hand);
	print_timestamp(prg, action, "has taken a fork\n");
	action->fork++;
	pthread_mutex_lock(action->r_hand);
	print_timestamp(prg, action, "has taken a fork\n");
	action->fork++;
}

void	down_fork(p_action *action)
{
	pthread_mutex_unlock(action->l_hand);
	pthread_mutex_unlock(action->r_hand);
}

/* Each philo will need to eat before sleep */
/* When he wakes up, he will do some thinking before eating again */
void	*philo_action(void	*arg)
{
	t_prg		*prg;
	p_action	*action;
	
	prg = (t_prg *)arg;
	action = NULL;
	if (prg->n_philo % 2 == 0)
		usleep(2500);
	if ((action->fork = 0))
		grab_fork(prg, action);
	else if (action->fork == 2)
	{
		philoeat(prg, action);
		down_fork(action);
		action->fork = 0;
		philosleep_then_think(prg, action);
	}
	return (NULL);
}
