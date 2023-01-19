/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/01/19 19:38:29 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Start of the main function */
int main(int ac, char **av)
{
	t_prg	prg;

	if (error_check(ac, av))
		return (1);
	int_struct(&prg, ac, av);
	init_thread();
	return (0);
}
