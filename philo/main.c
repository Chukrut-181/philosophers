/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/23 15:25:37 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	**array;

	if (argc != 5 && argc != 6)
	{
		printf("Wrong argument count: Only 4 or 5 arguments\n");
		return (1);
	}
	array = ft_parse_argv(argc, &argv[1]);
	ft_checkprinter(argc, array);
	return (0);
}

void	ft_checkprinter(int argc, int **array)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		printf("int array[%d] = %d\n", i, *array[i]);
		free(array[i]);
		i++;
	}
	free(array);
}
