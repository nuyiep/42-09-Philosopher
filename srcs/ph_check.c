/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:49 by plau              #+#    #+#             */
/*   Updated: 2023/02/13 19:03:45 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* (Optional) Return 1 if each philo has eaten at least x number of times */
int	check_if_all_ate(t_prg *prg)
{
	if (prg->action->ph_ate == prg->n_philo)
	{
		prg->action->finish = true;
		return (1);
	}
	return (0);
}

/* Returns 1 if the philosopher is dead */
// printf("%d %d %d\n", action->last_meal, gettime(), action->prg->time_to_die);
int	check_if_dead(t_action *action)
{
	pthread_mutex_lock(&action->philo_mutex);
	if ((action->last_meal + action->prg->time_to_die) < current_time(action->prg))
	{
		print_timestamp(action->prg, "died", action->id);
		action->should_die = true;
		action->finish = true;
		pthread_mutex_unlock(&action->philo_mutex);
		return (1);
	}
	pthread_mutex_unlock(&action->philo_mutex);
	usleep(100);
	return (0);
}
