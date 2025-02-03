/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:29:15 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:32:49 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************* */
/*  ft_destroy_mutexes                                                       */
/*                                                                           */
/*  Destroys all mutexes used in the simulation to free resources. It loops  */
/*  through the forks and destroys each mutex, and then it destroys the      */
/*  other mutexes related to the simulation's state and printing.            */
/*                                                                           */
/*  life: Pointer to the life structure, used to access the necessary mutexes*/
/*        for simulation state management.                                   */
/*  forks: Array of mutexes representing the philosophers' forks.            */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_destroy_mutexes(t_life *life, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < MAXPHILOS)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&life->print);
	pthread_mutex_destroy(&life->eat);
	pthread_mutex_destroy(&life->waiter);
}

/* ************************************************************************* */
/*  ft_end_condition                                                         */
/*                                                                           */
/*  Checks whether the simulation should end. It checks the global status    */
/*  of the simulation and the philosopher's current status. If either        */
/*  indicates that the simulation has ended or the philosopher is no longer  */
/*  in a valid state to continue (i.e., not philosophizing), the function    */
/*  returns 1, signaling the end of the philosopher's routine. Otherwise,    */
/*  it returns 0, allowing the philosopher to continue.                      */
/*                                                                           */
/*  philo: Pointer to the philosopher structure, used to access their        */
/*         current state and the global simulation state.                    */
/*                                                                           */
/*  Returns: 1 if the simulation should end, 0 if the philosopher can        */
/*           continue.                                                       */
/* ************************************************************************* */
int	ft_end_condition(t_philo *philo)
{
	t_life	*life;

	life = philo->life;
	pthread_mutex_lock(&life->waiter);
	if (life->status != CONTINUE || philo->status != PHILOSOPHING)
	{
		pthread_mutex_unlock(&life->waiter);
		return (1);
	}
	pthread_mutex_unlock(&life->waiter);
	return (0);
}
