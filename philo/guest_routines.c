/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guest_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:18 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:31:06 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************* */
/*  ft_philo_routine                                                         */
/*                                                                           */
/*  The routine for each philosopher thread. It first sleeps for a brief     */
/*  time if the philosopher's ID is even, then continuously runs the cycle   */
/*  of eating, sleeping, and thinking until the end condition is met.        */
/*                                                                           */
/*  philo: Pointer to the philosopher structure, containing the philosopher's*/
/*         ID and other information for simulation.                          */
/*                                                                           */
/*  Returns: NULL when the philosopher's routine finishes.                   */
/* ************************************************************************* */
void	*ft_philo_routine(void *philo)
{
	t_philo	*guest;
	t_life	*life;

	guest = (t_philo *)philo;
	life = guest->life;
	if (guest->id % 2 == 0)
		ft_usleep(10);
	while (ft_end_condition(philo) == 0)
	{
		ft_eat(guest, life);
		ft_sleep(guest);
		ft_think(guest);
	}
	return (NULL);
}

/* ************************************************************************* */
/*  ft_sleep                                                                 */
/*                                                                           */
/*  Simulates a philosopher sleeping. It prints the "sleeping" status and    */
/*  then sleeps for the specified time, defined by the 'ttsleep' parameter.  */
/*                                                                           */
/*  philo: Pointer to the philosopher structure, used to access their life   */
/*         and the time-to-sleep parameter.                                  */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_sleep(t_philo *philo)
{
	ft_printer(philo, SLEEPING);
	ft_usleep(philo->life->ttsleep);
}

/* ************************************************************************* */
/*  ft_think                                                                 */
/*                                                                           */
/*  Simulates a philosopher thinking. It prints the "thinking" status.       */
/*                                                                           */
/*  philo: Pointer to the philosopher structure, used to access their life  */
/*         and status.                                                       */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_think(t_philo *philo)
{
	ft_printer(philo, THINKING);
}

/* ************************************************************************* */
/*  ft_eat                                                                   */
/*                                                                           */
/*  Simulates a philosopher eating. It locks the philosopher's forks,        */
/*  prints the "got fork" and "eating" statuses, and updates the number of   */
/*  meals eaten. If the philosopher has eaten the required number of times,  */
/*  their status is updated to FINISHED. The philosopher then eats for the   */
/*  specified time and unlocks the forks.                                    */
/*                                                                           */
/*  philo: Pointer to the philosopher structure, used to access their        */
/*         current state and fork pointers.                                  */
/*  life: Pointer to the simulation life structure, used to access the time  */
/*        to eat and the 'must_eat' parameter.                               */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_eat(t_philo *philo, t_life *life)
{
	pthread_mutex_lock(philo->right_fork);
	ft_printer(philo, GOTFORK);
	pthread_mutex_lock(philo->left_fork);
	ft_printer(philo, GOTFORK);
	ft_printer(philo, EATING);
	pthread_mutex_lock(&life->eat);
	philo->meals_eaten++;
	philo->time_of_lm = ft_get_current_time();
	if (life->must_eat != 0 && philo->meals_eaten == life->must_eat)
		philo->status = FINISHED;
	pthread_mutex_unlock(&life->eat);
	ft_usleep(life->tteat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
