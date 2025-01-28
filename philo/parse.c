/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:59:52 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/28 15:48:19 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Must take exactly 4 or 5 arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > MAXPHILOS)
	{
		printf("Error: Cannot seat more than 250 philosophers at the table\n");
		return (1);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Error: No point setting up a table for less than 1 guest\n");
		return (1);
	}
	return (0);
}
