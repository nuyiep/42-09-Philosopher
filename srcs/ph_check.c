/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:49 by plau              #+#    #+#             */
/*   Updated: 2023/02/10 19:26:53 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* (Option) Return 1 if each philo has eaten at least x number of times */
int	check_if_all_ate(t_prg *prg)
{
	int	i;

	i = 0;
	while (prg->action->finish == false)
	{
		if (prg->action->eat_check == prg->n_philo)
			prg->action->finish = true;
	}
	return (1);
}

/* Returns 1 if the philosopher is dead */
int	check_if_dead(t_action *action)
{
	pthread_mutex_lock(&action->philo_mutex);
	// printf("%d %d %d\n", action->last_meal, gettime(), action->prg->time_to_die);
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
