/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:59:52 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/28 10:44:51 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	**ft_parse_argv(int argc, char **argv)
{
	int	**array;
	int	i;

	array = malloc(sizeof(int *) * (argc -1));
	i = 0;
	while (argv[i])
	{
		array[i] = malloc(sizeof(int));
		*array[i] = ft_atoi(argv[i]);
		if (!array[i])
			printf("Failed mallocating array[x]\n");
		i++;
	}
	return (array);
}

int	ft_check_argc(int argc)
{
	if (argc < 5)
	{
		printf("Too few arguments: Must take at least 4\n");
		return (1);
	}
	else if (argc > 6)
	{
		printf("Too many arguments: Cannot take more than 5\n");
		return (1);
	}
	return (0);
}
