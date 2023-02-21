/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:21:49 by plau              #+#    #+#             */
/*   Updated: 2023/02/21 13:56:14 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Return 1 if each philo has eaten at least x number of times */
int	check_if_all_ate(t_prg *prg)
{
	int	ph_ate;
	int	i;

	i = 0;
	ph_ate = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_lock(&(prg->action[i].eat_mutex));
		if (prg->action[i].eat_check >= prg->must_eat)
		{
			ph_ate++;
			if (ph_ate == prg->n_philo)
			{
				prg->finish = 1;
				pthread_mutex_unlock(&(prg->action[i].eat_mutex));
				return (1);
			}
		}
		pthread_mutex_unlock(&(prg->action[i].eat_mutex));
		i++;
	}
	return (0);
}

/* keep checking within the while loop if no one dies */
// printf("%d %d %d\n", action->last_meal, gettime(), action->prg->time_to_die);
void	*check_if_dead(void	*action_in)
{
	t_action	*action;

	action = (t_action *)action_in;
	pthread_mutex_lock(&action->prg->monitor_mutex);
	pthread_mutex_lock(&action->eat_mutex);
	while (!((current_time(action->prg) - action->last_meal)
			>= action->prg->time_to_die))
	{
		pthread_mutex_unlock(&action->eat_mutex);
		usleep(action->prg->time_to_die / 2);
		pthread_mutex_lock(&action->eat_mutex);
	}
	pthread_mutex_unlock(&action->eat_mutex);
	print_timestamp(action->prg, "died", action->id);
	pthread_mutex_lock(&action->prg->philo_mutex);
	action->prg->finish = 1;
	pthread_mutex_unlock(&action->prg->philo_mutex);
	pthread_mutex_unlock(&action->prg->monitor_mutex);
	return (NULL);
}

/* Check if dead and check if all ate */
int	check_status(t_action *action)
{
	pthread_mutex_lock(&action->prg->philo_mutex);
	if (action->prg->finish == 1)
	{
		pthread_mutex_unlock(&action->prg->philo_mutex);
		return (1);
	}
	if (action->prg->must_eat > 0)
	{
		if (check_if_all_ate(action->prg) == 1)
		{	
			action->prg->finish = 1;
			pthread_mutex_unlock(&action->prg->philo_mutex);
			return (1);
		}
	}
	pthread_mutex_unlock(&action->prg->philo_mutex);
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
