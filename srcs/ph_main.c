/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/02/03 18:21:39 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Start of the main function */
int	main(int ac, char **av)
{
	t_prg		prg;
	p_action	action;

	if (error_check(&prg, ac, av))
		return (1);
	int_struct(&prg, ac, av);
	int_struct2(&action);
	create_philos(&prg, &action);
	if (ft_atoi(av[1]) == 1)
		return (force_death(&prg, &action));
	//init_thread();
	return (0);
}
