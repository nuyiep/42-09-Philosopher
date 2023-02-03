/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:49 by plau              #+#    #+#             */
/*   Updated: 2023/02/02 18:39:36 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Check whether each philo has eaten at least x number of times */
int	check_eat(t_prg *prg)
{
	int	i;
	int	check;
	
	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_lock(&prg->must_eat[i]);
		check = prg->must_eat[i];
		pthread_mutex_unlock(&prg->must_eat[i]);
		if (check != 0)
			return (0);
		i++;
	}
	return (1);
}

/* Check if philo is dead */
/* Return 1 if died **/
int	check_death(t_prg *prg, p_action *action)
{
	if ((action->last_meal + prg->time_to_die) < gettime())
	{
		printf("Philo died");
		return (1);
	}
}
