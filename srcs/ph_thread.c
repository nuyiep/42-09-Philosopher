/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:34:09 by plau              #+#    #+#             */
/*   Updated: 2023/02/03 16:17:49 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Initialize the fork mutex for each philosophers */
void	ph_init_mutex(t_prg *prg, p_action *action)
{
	int	i;

	i = 0;
	pthread_mutex_init(&action->main_lock, NULL);
	while (i < prg->n_philo)
		pthread_mutex_init(&action->forks[i++], NULL);
}
