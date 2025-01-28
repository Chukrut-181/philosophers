/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/28 16:44:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_initphilos(int ac, char **av, t_philo *philo, pthread_mutex_t *fork)
{
	int	guests;
	int	i;

	guests =  ft_atoi(av[1]);
	i = 0;
	while (i < guests)
	{
		philo[i].id = i;
		philo[i].time_of_lm = ft_get_current_time();
	}
	
}

int	main(int argc, char **argv)
{
	t_philo			philo[MAXPHILOS];
	pthread_mutex_t	fork[MAXPHILOS];

	if (ft_check_args(argc, argv))
		return (1);
	ft_memset(&philo, 0, sizeof(t_philo));
	ft_memset(&fork, 0, sizeof(t_life));
	ft_fill_philo_data(argc, argv, philo, fork);
	return (0);
}

/* void	ft_checkprinter(int argc, int **array)
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
} */
