/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:21:43 by plau              #+#    #+#             */
/*   Updated: 2023/02/07 20:36:47 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Forces the philosopher to die at death time when there is only 1 */
/* usleep takes in microseconds */
int	force_death(t_prg *prg)
{
	usleep(prg->time_to_die);
	printf("%d\t %d died\n", prg->time_to_die, prg->action->id);
	return (0);
}
