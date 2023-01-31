/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:52 by plau              #+#    #+#             */
/*   Updated: 2023/01/30 17:25:02 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Return 1 if error */
int	error_check(t_prg *prg, int ac, char **av)
{
	int	i;
	
	i = 1;
	if (ac < 5)
	{
		error_message("Less than 5 arguments");
		return (1);
	}
	if (ac > 6)
	{
		error_message("More than 6 arguments");
		return (1);
	}
	while (av[i] != 0)
	{
		if (is_digit(av[i]) == 0)
		{
			error_message("Invalid arguments- Not digits");
			return (1);
		}
		i++;
	}
	return (0);
	(void)prg;
}

/* Print error message */
void	error_message(char *str)
{
	printf("Error: %s\n", str);
}

/* Get time */
long int	gettime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + tv.tv_usec);	
}
