/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:43 by plau              #+#    #+#             */
/*   Updated: 2023/02/06 20:30:27 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Forces the philosopher to die at death time when there is only 1 */
/* usleep takes in microseconds */
int	force_death(t_prg *prg, p_action *action)
{
	usleep(prg->time_to_die);
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
		action[i].last_meal = action->start_time;
		pthread_create(&action->thread_id[i], NULL, philo_action,
			&(action[i]));
		printf("Thread %d has started\n", i);
		i++;
	}
	while (i < prg->n_philo)
	{
		pthread_join(action->thread_id[i], NULL);
		i++;
	}
}
