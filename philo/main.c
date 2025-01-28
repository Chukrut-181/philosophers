/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/28 10:42:44 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	//int			**array;
	pthread_t	t1;
	pthread_t	t2;

	if (ft_check_argc(argc))
		return (1);
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_create(&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Hello from process\n");
	//array = ft_parse_argv(argc, &argv[1]);
	//ft_checkprinter(argc, array);
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
