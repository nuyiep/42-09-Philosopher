/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:31:36 by plau              #+#    #+#             */
/*   Updated: 2023/02/07 21:26:46 by plau             ###   ########.fr       */
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

void	grab_fork(t_prg *prg, t_fork *left, t_fork *right)
{
	pthread_mutex_lock(&left->fork_mutex);
	print_timestamp(prg, "has taken a fork\n");
	prg->action->fork++;
	pthread_mutex_lock(&right->fork_mutex);
	print_timestamp(prg, "has taken a fork\n");
	prg->action->fork++;
}

void	down_fork(t_fork *left, t_fork *right)
{
	pthread_mutex_unlock(&left->fork_mutex);
	pthread_mutex_unlock(&right->fork_mutex);
}

/* Each philo will need to eat before sleep */
/* When he wakes up, he will do some thinking before eating again */
void	*philo_action(void	*action_in)
{
	// t_prg		*prg;
	p_action	*action;
	// t_fork		*left;
	// t_fork		*right;
	
	printf("Started\n");
	action = (p_action *)action_in;
	printf("%d\n", action->last_meal);
// 	left = NULL;
// 	right = NULL;
// 	if (prg->n_philo % 2 == 0)
// 		usleep(2500);
// 	if (prg->action->fork == 0)
// 		grab_fork(prg, left, right);
// 	else if (prg->action->fork == 2)
// 	{
// 		philoeat(prg);
// 		down_fork(left, right);
// 		prg->action->fork = 0;
// 		philosleep_then_think(prg);
// 	}
	return (NULL);
}
