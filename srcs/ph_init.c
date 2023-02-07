/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:15:44 by plau              #+#    #+#             */
/*   Updated: 2023/02/07 21:27:27 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Initialize struct */
t_prg	*int_struct(t_prg *prg, int ac, char **av)
{
	if (prg == NULL)
		return (NULL);
	prg->n_philo = ft_atoi(av[1]);
	prg->time_to_die = (ft_atoi(av[2]) * 1000);
	prg->time_to_eat = (ft_atoi(av[3]) * 1000);
	prg->time_to_sleep = (ft_atoi(av[4]) * 1000);
	prg->must_eat = 0;
	if (ac == 6)
		prg->must_eat = ft_atoi(av[5]);
	prg->action = malloc(sizeof(p_action) * prg->n_philo);
	prg->action->fork = 0;
	return (prg);
}

/* Create a thread for each philosopher */
void	create_philos(t_prg *prg)
{
	int			i;
	pthread_t	temp;

	i = 0;
	printf("Thread %d has started\n", i);
	while (i < prg->n_philo)
	{
		prg->action[i].id = i + 1;
		prg->action[i].eat_check = 0;
		prg->action[i].last_meal = prg->action->start_time;
		pthread_mutex_init(&prg->action[i].philo_mutex, NULL);
		pthread_create(&temp, NULL, philo_action, &(prg->action[i]));
		pthread_detach(temp);
		i++;
	}
}

/* Initializes the fork mutexes for each philosophers */
void	init_fork(t_prg *prg)
{
	t_fork	*forks;
	int		i;
	
	forks = malloc(prg->n_philo *sizeof(t_fork));
	if (forks == NULL)
		return ;
	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_init(&(forks[i].fork_mutex), NULL);
		forks[i].n = i;
		i++;
	}
}
