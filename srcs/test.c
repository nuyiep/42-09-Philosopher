/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:42:32 by plau              #+#    #+#             */
/*   Updated: 2023/02/01 15:08:04 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void*	myturn( void *arg)
// {
// 	int	i;
// 	int	*iptr = (int *)arg;

// 	i = 0;
// 	while (i < 8)
// 	{
// 		sleep(1);
// 		printf("My turn! %d %d\n", i, *iptr);
// 		(*iptr)++;
// 		i++;
// 	}
// 	return (NULL);
// 	(void)arg;
// }

// void	yourturn()
// {
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		sleep(2);
// 		printf("Your turn! %d\n", i);
// 		i++;
// 	}
// }

// int main(void)
// {
// 	pthread_t	newthread;
// 	int			v;

// 	v = 5;
// 	pthread_create(&newthread, NULL, myturn, &v);
// 	// myturn();
// 	yourturn();
// 	pthread_join(newthread, NULL);
// 	printf("thread's done: v=%d\n", v);
// }
