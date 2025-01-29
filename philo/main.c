/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 10:48:52 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_threads(t_philo *philo, t_life *life, pthread_mutex_t *fork)
{
	pthread_t	waiter;
	int			i;
	
	pthread_create(&waiter, NULL, &ft_waiter_routine, philo);
	while (i < life->number_of_philos)
	{
		pthread_create(&philo->thread, NULL, &ft_philo_routine, &philo[i]);
		i++;
	}
	
}

void	ft_initlife(int argc, char **argv, t_life *life)
{
	life->number_of_philos = ft_atoi(argv[1]);
	life->ttdie = ft_atoi(argv[2]);
	life->tteat = ft_atoi(argv[3]);
	life->ttsleep = ft_atoi(argv[4]);
	if (argc == 6)
		life->must_eat = ft_atoi(argv[5]);
}

void	ft_initphilos(char **av, t_philo *philo, pthread_mutex_t *fork)
{
	int	guests;
	int	i;

	guests =  ft_atoi(av[1]);
	i = 0;
	while (i < guests)
	{
		philo[i].id = i;
		philo[i].time_of_lm = ft_get_current_time();
		philo[i].right_fork = &fork[i];
		if (i == 0)
			philo[i].right_fork = &fork[guests - 1];
		else
			philo[i].right_fork = &fork[i - 1];
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo			philo[MAXPHILOS];
	t_life			life;
	pthread_mutex_t	fork[MAXPHILOS];

	if (ft_check_args(argc, argv))
		return (1);
	ft_memset(&philo, 0, sizeof(t_philo));
	ft_memset(&fork, 0, sizeof(t_life));
	ft_initphilos(argv, philo, fork);
	ft_initlife(argc, argv, &life);
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
