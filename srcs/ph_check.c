/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:49 by plau              #+#    #+#             */
/*   Updated: 2023/02/16 19:01:30 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* (Optional) Return 1 if each philo has eaten at least x number of times */
int	check_if_all_ate(t_prg *prg)
{
	int	i;

	i = 1;
	while (i <= prg->n_philo)
	{
		pthread_mutex_lock(&(prg->action->philo_mutex));
		if (prg->action[i].eat_check == prg->must_eat)
			prg->action[i].ph_ate++;
		pthread_mutex_unlock(&(prg->action->philo_mutex));
		if (prg->action[i].ph_ate == prg->n_philo)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/* Returns 1 if the philosopher is dead */
// printf("%d %d %d\n", action->last_meal, gettime(), action->prg->time_to_die);
int	check_if_dead(t_action *action)
{
	pthread_mutex_lock(&action->philo_mutex);
	if ((action->last_meal + action->prg->time_to_die)
		< current_time(action->prg))
	{
		print_timestamp(action->prg, "died", action->id);
		pthread_mutex_unlock(&action->philo_mutex);
		return (1);
	}
	pthread_mutex_unlock(&action->philo_mutex);
	usleep(100);
	return (0);
}

/* Check if dead and check if all ate */
int	check_status(t_action *action)
{
	if (check_if_dead(action) == 1)
	{
		action->prg->finish = 1;
		return (1);
	}
	if (action->prg->must_eat > 0)
	{
		if (check_if_all_ate(action->prg) == 1)
		{	
			action->prg->finish = 1;
			if (action->eat_check < action->prg->must_eat)
				printf("%d	%d %s\n", current_time(action->prg),
					action->id, "is eating");
			return (1);
		}
	}
	return (0);
}

/* Print error message */
int	print_error(char *str)
{
	printf("Error: %s\n", str);
	return (1);
}

/* Return 1 if error */
int	error_check(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5)
		return (print_error("Less than 5 arguments"));
	if (ac > 6)
		return (print_error("More than 6 arguments"));
	while (i < ac)
	{
		if (is_digit(av[i]) == 0)
			return (print_error("Input must only be numbers"));
		i++;
	}
	return (0);
}
