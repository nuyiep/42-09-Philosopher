/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/02/21 11:56:55 by plau             ###   ########.fr       */
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
	free_destroy(prg);
	system("leaks -q philo");
	return (0);
}

/* Each philo will need to eat before sleep */
/* When he wakes up, he will do some thinking before eating again */
void	*philo_action(void	*action_in)
{
	t_action	*action;

	action = (t_action *)action_in;
	while (wait_start(action) == 0)
	{
	}
	if (action->id % 2 == 0)
		ft_usleep(2500);
	while (1)
	{
		if (check_status(action) == 1)
			return (NULL);
		if (ph_action(action) == 1)
			return (NULL);
	}
	return (NULL);
}
