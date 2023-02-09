/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:49 by plau              #+#    #+#             */
/*   Updated: 2023/02/09 17:32:21 by plau             ###   ########.fr       */
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
	while (action->finish == false)
	{
		printf("start time : %d\n", action->start_time);
		printf("last eat : %d\n", (action->last_meal + action->prg->time_to_die));
		if ((action->last_meal + action->prg->time_to_die) < (gettime() - action->start_time))
		{
			printf("die\n");
			print_timestamp(action->prg, "died\n");
			action->should_die = true;
			action->finish = true;
			return (1);
		}
		usleep(100);
	}
	printf("live\n");
	return (0);
}
