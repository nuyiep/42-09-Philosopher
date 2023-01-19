/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:16:39 by plau              #+#    #+#             */
/*   Updated: 2023/01/19 15:42:09 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Start of the main function */
/* t1 - holds the info of the thread we create */
/* Create the thread */
/* pthread_join - wait the process to finish the execution */
int main(int ac, char **av)
{
	pthread_t	t1;

	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL); 
	(void)ac;
	(void)av;
	return (0);
}