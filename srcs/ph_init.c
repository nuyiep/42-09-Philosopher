/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:15:44 by plau              #+#    #+#             */
/*   Updated: 2023/02/06 15:36:00 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Initialize struct according to av */
void	int_struct(t_prg *prg, int ac, char **av)
{
	prg->n_philo = ft_atoi(av[1]);
	prg->time_to_die = (ft_atoi(av[2]) * 1000);
	prg->time_to_eat = (ft_atoi(av[3]) * 1000);
	prg->time_to_sleep = (ft_atoi(av[4]) * 1000);
	prg->must_eat = 0;
	if (ac == 6)
		prg->must_eat = ft_atoi(av[5]);
}

/* Initialize struct 2 */
void	int_struct2(p_action *action)
{
	action->id = 1;
	action->start_time = gettime();
	action->last_meal = 0;
	action->fork = 0;
}
