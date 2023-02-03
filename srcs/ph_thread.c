/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:34:09 by plau              #+#    #+#             */
/*   Updated: 2023/02/02 19:30:45 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mails = 0;
pthread_mutex_t mutex;

/* Main routine performed by the thread */
/* Mutex - a lock around a section of code */
/* Mutex - to prevent the race condition */
/* (to prevent other threads from executing it at the same time) */
// void	routine()
// {
// 	int	i;

// 	i = 0;
// 	while (i < 10000000)
// 	{
// 		pthread_mutex_lock(&mutex);		
// 		mails++;
// 		pthread_mutex_unlock(&mutex);
// 		i++;
// 	}
// }

/* Create thread */
/* Initialize mutex and destroy mutex */
/* t1 - holds the info of the thread we create */
/* pthread_join - wait the thread to finish the execution */
// void	init_thread(void)
// {
// 	pthread_t		th[4];
// 	int				i;

// 	i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	while (i < 4)
// 	{
// 		if (pthread_create(&th[i], NULL, routine, NULL) != 0)
// 			return (print_error("Failed to create thread"));
// 		printf("Thread %d has started\n", i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (pthread_join(th[i], NULL) != 0)
// 			return (print_error("Failed to join thread"));
// 		printf("Thread %d has finished exection\n", i);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Number of mails: %d\n", mails);
// }
