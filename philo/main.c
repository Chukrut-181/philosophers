/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 15:46:35 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_threads(t_philo *philo, t_life *life)
{
	//pthread_t	waiter;
	int			i;

	i = 0;
	//pthread_create(&waiter, NULL, &ft_waiter_routine, philo);
	while (i < life->number_of_philos)
	{
		pthread_create(&philo[i].thread, NULL, &ft_philo_routine, &philo[i]);
		i++;
	}
	//pthread_join(waiter, NULL);
	i = 0;
	while (i < life->number_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

void	ft_initlife(int argc, char **argv, t_life *life)
{
	life->number_of_philos = ft_atoi(argv[1]);
	life->start_time = ft_get_current_time();
	life->ttdie = ft_atoi(argv[2]);
	life->tteat = ft_atoi(argv[3]);
	life->ttsleep = ft_atoi(argv[4]);
	pthread_mutex_init(&life->print, NULL);
	if (argc == 6)
		life->must_eat = ft_atoi(argv[5]);
}

void	ft_initphilos(char **av, t_philo *philo,
	pthread_mutex_t *fork, t_life *life)
{
	int	guests;
	int	i;

	guests = ft_atoi(av[1]);
	i = 0;
	while (i < guests)
	{
		philo[i].id = i + 1;
		philo[i].time_of_lm = ft_get_current_time();
		philo[i].right_fork = &fork[i];
		if (i == 0)
			philo[i].right_fork = &fork[guests - 1];
		else
			philo[i].right_fork = &fork[i - 1];
		philo[i].life = life;
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
	ft_initphilos(argv, philo, fork, &life);
	ft_initlife(argc, argv, &life);
	ft_init_threads(philo, &life);
	pthread_mutex_destroy(&life.print);
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
