/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:15:44 by plau              #+#    #+#             */
/*   Updated: 2023/02/18 14:48:06 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Initialize struct */
void	int_struct(t_prg *prg, int ac, char **av)
{
	if (prg == NULL)
		return ;
	prg->n_philo = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = (ft_atoi(av[3]) * 1000);
	prg->time_to_sleep = (ft_atoi(av[4]) * 1000);
	prg->must_eat = 0;
	prg->finish = 0;
	if (ac == 6)
		prg->must_eat = ft_atoi(av[5]);
	prg->action = malloc(sizeof(t_action) * prg->n_philo);
}

/* Create a thread for each philosopher */
/* pthread_join is similar to a wait function for child process */
void	create_philos(t_prg *prg)
{
	int			i;
	pthread_t	temp;

	i = 0;
	while (i < prg->n_philo)
	{
		prg->action[i].id = i + 1;
		prg->action[i].ph_ate = 0;
		prg->action[i].eat_check = 0;
		prg->action[i].start_time = gettime();
		prg->action[i].last_meal = current_time(prg);
		prg->action[i].fork = 0;
		prg->action[i].prg = prg;
		pthread_mutex_init(&prg->action[i].philo_mutex, NULL);
		pthread_mutex_init(&prg->action[i].write_mutex, NULL);
		pthread_create(&temp, NULL, philo_action, &(prg->action[i]));
		i++;
	}
	pthread_join(temp, NULL);
}

/* Initializes the fork mutexes for each philosophers */
/* Right fork is their own fork */
/* Left fork is the next philo's fork */
/* PS: i start with zero here, hence n_philo - 1 */
void	init_fork(t_prg *prg)
{
	t_fork		*forks;
	int			i;

	forks = malloc(prg->n_philo * sizeof(t_fork));
	if (forks == NULL)
		return ;
	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_init(&(forks[i].fork_mutex), NULL);
		prg->action[i].right = &forks[i];
		if (i != prg->n_philo - 1)
			prg->action[i + 1].left = &forks[i];
		else
			prg->action[0].left = &forks[i];
		i++;
	}
	prg->fork = forks;
}
