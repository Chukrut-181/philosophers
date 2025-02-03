/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:17:44 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:28:38 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************* */
/*  ft_waiter_routine                                                        */
/*                                                                           */
/*  The routine for the waiter thread. Continuously checks for philosophers  */
/*  who are either dead or finished eating and ends the simulation when      */
/*  necessary.                                                               */
/*                                                                           */
/*  philo: Pointer to the philosopher structure, used to access their life   */
/*         and status.                                                       */
/*                                                                           */
/*  Returns: NULL when the routine finishes execution.                       */
/* ************************************************************************* */
void	*ft_waiter_routine(void *philo)
{
	t_philo	*guest;
	t_life	*life;

	guest = (t_philo *)philo;
	life = guest->life;
	while (1)
	{
		if (ft_check_for_corpses(guest, life) || ft_check_for_end(guest, life))
			break ;
	}
	return (NULL);
}

/* ************************************************************************* */
/*  ft_check_for_corpses                                                     */
/*                                                                           */
/*  Checks all philosophers to see if any have died due to exceeding the     */
/*  time limit without eating. If a philosopher is dead, it updates their    */
/*  status and sets the simulation status to STOP. It also prints the death  */
/*  message and returns 1.                                                   */
/*                                                                           */
/*  philo: Array of philosopher structures, each containing their last meal  */
/*         time and status.                                                  */
/*  life: Pointer to the 't_life' structure, used to manage the simulation   */
/*        status and the time-to-die parameter.                              */
/*                                                                           */
/*  Returns: 1 if a philosopher is dead, 0 otherwise.                        */
/* ************************************************************************* */
int	ft_check_for_corpses(t_philo *philo, t_life *life)
{
	int	i;

	i = 0;
	while (i < life->number_of_philos)
	{
		pthread_mutex_lock(&life->waiter);
		if (((ft_get_current_time() - philo[i].time_of_lm) > life->ttdie)
			&& philo[i].status != EATING)
		{
			philo[i].status = DEAD;
			life->status = STOP;
			pthread_mutex_unlock(&life->waiter);
			ft_printer(&philo[i], DEAD);
			return (1);
		}
		pthread_mutex_unlock(&life->waiter);
		i++;
	}
	return (0);
}

/* ************************************************************************* */
/*  ft_check_for_end                                                         */
/*                                                                           */
/*  Checks if all philosophers have finished eating the required number      */
/*  of times. If any philosopher is still eating, the function returns 0.    */
/*  If all philosophers are done, it sets the simulation status to STOP,     */
/*  prints a message indicating all guests have eaten the required times,    */
/*  and returns 1.                                                           */
/*                                                                           */
/*  philo: Array of philosopher structures, each containing their current    */
/*         status.                                                           */
/*  life: Pointer to the 't_life' structure, used to manage the simulation   */
/*        and track how many times each philosopher must eat.                */
/*                                                                           */
/*  Returns: 0 if any philosopher is still eating, 1 if the simulation ends. */
/* ************************************************************************* */
int	ft_check_for_end(t_philo *philo, t_life *life)
{
	int	i;

	i = 0;
	while (i < life->number_of_philos)
	{
		if (philo[i].status == PHILOSOPHING)
			return (0);
		else
			i++;
	}
	pthread_mutex_lock(&life->waiter);
	life->status = STOP;
	pthread_mutex_unlock(&life->waiter);
	printf("\033[91mEnd: All guests ate %i times\033[0m\n", life->must_eat);
	return (1);
}
