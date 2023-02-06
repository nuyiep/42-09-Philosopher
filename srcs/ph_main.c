/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/02/06 16:28:40 by plau             ###   ########.fr       */
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
	// if (ft_atoi(av[1]) == 1)
	// 	return (force_death(&prg, &action));
	create_philos(&prg, &action);
	return (0);
}
