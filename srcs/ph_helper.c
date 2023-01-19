/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:40:52 by plau              #+#    #+#             */
/*   Updated: 2023/01/19 19:23:36 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_check(int ac, char **av)
{
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
	return (0);
	(void)av;
}

void	error_message(char *str)
{
	printf("Error: %s\n", str);
}