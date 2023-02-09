/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/02/09 17:34:04 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Start of the main function */
int	main(int ac, char **av)
{
	t_prg		*prg;
	
	prg = malloc(sizeof(t_prg)); 
	if (error_check(ac, av))
		return (1);
	int_struct(prg, ac, av);
	init_fork(prg);
	create_philos(prg);
	if (ft_atoi(av[1]) == 1)
		return (force_death(prg));
	return (0);
}
