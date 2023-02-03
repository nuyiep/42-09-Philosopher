/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:43 by plau              #+#    #+#             */
/*   Updated: 2023/02/03 18:11:39 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Forces the philosopher to die at death time when there is only 1 */
/* usleep takes in microseconds */
int	force_death(t_prg *prg, p_action *action)
{
	usleep(prg->time_to_die * 1000);
	printf("%d\t %d died\n", prg->time_to_die, action->id);
	return (0);
}

/* Create a thread for each philosopher */
void	create_philos(t_prg *prg, p_action *action)
{
	int			i;

	i = 0;
	while (i < prg->n_philo)
	{
		pthread_create(&action->philo[i].thread, NULL, philo_action(prg, action), 
			&action->philo[i]);
		i++;
	}
}
