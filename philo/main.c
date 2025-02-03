/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:17:51 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:39:35 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************* */
/*  ft_init_threads                                                          */
/*                                                                           */
/*  Initializes the philosopher threads and the waiter thread. It creates    */
/*  the threads for each philosopher and starts their routines. It also      */
/*  creates a separate waiter thread and waits for all threads to finish.    */
/*                                                                           */
/*  philo: Array of philosopher structures, each containing a thread.        */
/*  life: Pointer to the 't_life' structure, containing simulation details.  */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_init_threads(t_philo *philo, t_life *life)
{
	pthread_t	waiter;
	int			i;

	i = 0;
	pthread_create(&waiter, NULL, &ft_waiter_routine, philo);
	while (i < life->number_of_philos)
	{
		pthread_create(&philo[i].thread, NULL, &ft_philo_routine, &philo[i]);
		i++;
	}
	pthread_join(waiter, NULL);
	i = 0;
	while (i < life->number_of_philos)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}

/* ************************************************************************* */
/*  ft_init_life                                                             */
/*                                                                           */
/*  Initializes the life structure for the philosopher simulation. It sets   */
/*  up the number of philosophers, their initial status, and the time values */
/*  for dying, eating, and sleeping. It also initializes necessary mutexes.  */
/*  If the argument count is 6, it sets the number of meals each philosopher */
/*  must eat.                                                                */
/*                                                                           */
/*  argc: Number of arguments passed to the program.                         */
/*  argv: Array of argument strings.                                         */
/*  life: Pointer to the 't_life' structure to be initialized.               */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_init_life(int argc, char **argv, t_life *life)
{
	life->number_of_philos = ft_atoi(argv[1]);
	life->status = CONTINUE;
	life->start_time = ft_get_current_time();
	life->ttdie = ft_atoi(argv[2]);
	life->tteat = ft_atoi(argv[3]);
	life->ttsleep = ft_atoi(argv[4]);
	pthread_mutex_init(&life->print, NULL);
	pthread_mutex_init(&life->eat, NULL);
	pthread_mutex_init(&life->waiter, NULL);
	if (argc == 6)
		life->must_eat = ft_atoi(argv[5]);
	else
		life->must_eat = 0;
}

/* ************************************************************************* */
/*  ft_init_philos                                                           */
/*                                                                           */
/*  Initializes the philosophers by setting their IDs, the time of the last  */
/*  meal, the left and right forks, and their initial status. It also links  */
/*  each philosopher to the life structure.                                  */
/*                                                                           */
/*  philo: Array of philosopher structures to be initialized.                */
/*  fork: Array of mutexes representing the forks used by philosophers.      */
/*  life: Pointer to the 't_life' structure, shared among all philosophers.  */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_init_philos(t_philo *philo, pthread_mutex_t *fork, t_life *life)
{
	int	i;

	i = 0;
	while (i < life->number_of_philos)
	{
		philo[i].id = (i + 1);
		philo[i].time_of_lm = ft_get_current_time();
		philo[i].meals_eaten = 0;
		philo[i].right_fork = &fork[i];
		if (i == 0)
		{
			philo[i].left_fork = &fork[life->number_of_philos - 1];
		}
		else
		{
			philo[i].left_fork = &fork[i - 1];
		}
		philo[i].status = PHILOSOPHING;
		philo[i].life = life;
		i++;
	}
}

/* ************************************************************************* */
/*  ft_init_forks                                                            */
/*                                                                           */
/*  Initializes the mutexes for each fork in the simulation. It loops through*/
/*  the number of philosophers and initializes a mutex for each fork.        */
/*                                                                           */
/*  forks: Array of mutexes representing the forks.                          */
/*  life: Pointer to the 't_life' structure, used to determine the number    */
/*        of philosophers.                                                   */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_init_forks(pthread_mutex_t *forks, t_life *life)
{
	int	i;

	i = 0;
	while (i < life->number_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

/* ************************************************************************* */
/*  main                                                                     */
/*                                                                           */
/*  Entry point of the philosophers program. It initializes philosophers,    */
/*  forks, and the simulation, then starts the philosopher threads. If only  */
/*  one philosopher is present, it runs a special case function. Finally,    */
/*  it cleans up all allocated resources.                                    */
/*                                                                           */
/*  argc: Number of arguments passed to the program.                         */
/*  argv: Array of argument strings.                                         */
/*                                                                           */
/*  Returns: 0 on success, 1 if argument validation fails.                   */
/* ************************************************************************* */
int	main(int argc, char **argv)
{
	t_philo			philo[MAXPHILOS];
	t_life			life;
	pthread_mutex_t	forks[MAXPHILOS];

	if (ft_check_args(argc, argv))
		return (1);
	ft_memset(&philo, 0, sizeof(t_philo));
	ft_memset(&forks, 0, sizeof(forks));
	ft_init_life(argc, argv, &life);
	ft_init_forks(forks, &life);
	ft_init_philos(philo, forks, &life);
	if (life.number_of_philos == 1)
		ft_dinnerforone(&philo[0]);
	else
		ft_init_threads(philo, &life);
	ft_destroy_mutexes(&life, forks);
	return (0);
}
