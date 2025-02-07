/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:59:52 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/07 16:29:50 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_argv5(char *argv)
{
	int	argv5;

	argv5 = ft_atoi(argv);
	if (argv5 > 1)
		return (0);
	else
	{
		printf("Error: Meals to be eaten must be a positive number\n");
		return (1);
	}
}

int	ft_check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Must take exactly 4 or 5 arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > MAXPHILOS)
	{
		printf("Error: Cannot seat more than 250 guests at the table\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Error: No point setting up a table for less than 1 guest\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 50 || ft_atoi(argv[3]) < 1 || ft_atoi(argv[4]) < 1)
	{
		printf("Error: Minimum time value is 50 milliseconds.\n");
		return (1);
	}
	if (argc == 6)
		return (ft_check_argv5(argv[5]));
	return (0);
}
