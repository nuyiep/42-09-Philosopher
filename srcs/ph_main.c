/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/02/07 21:12:15 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Start of the main function */
int	main(int ac, char **av)
{
	t_prg		prg;
	
	if (error_check(ac, av))
		return (1);
	int_struct(&prg, ac, av);
	pthread_mutex_init(&prg.action->write_mutex, NULL);
	prg.action->start_time = gettime();
	create_philos(&prg);
	init_fork(&prg);
	if (ft_atoi(av[1]) == 1)
		return (force_death(&prg));
	pthread_mutex_destroy(&prg.action->write_mutex);
	return (0);
}
