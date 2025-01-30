/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:18 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/30 11:23:39 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	*ft_waiter_routine(void *philo)
{
// CHECK ALL ALIVE -- CHECK NOT FINISHED

	t_philo	*guest;
	
	guest = (t_philo *)philo;
	
	return (NULL);
} */

void	*ft_philo_routine(void *philo)
{
	t_philo	*guest;

	guest = (t_philo *)philo;
	if (guest->id % 2 == 0)
		ft_usleep(100);
	while (guest->philo_status == PHILOSOPHING
		&& guest->life->life_status == CONTINUE)
	{
		if ((ft_get_current_time() - guest->time_of_lm) > guest->life->tteat)
		{
			guest->life->life_status = STOP;
			ft_usleep(500);
			ft_printer(guest, DEAD);
			break ;
		}
		ft_eat(guest);
		ft_sleep(guest);
		ft_think(guest);
	}
	return (NULL);
}

void	ft_sleep(t_philo *philo)
{
	ft_printer(philo, SLEEPING);
	ft_usleep(philo->life->ttsleep);
}

void	ft_think(t_philo *philo)
{
	ft_printer(philo, THINKING);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_printer(philo, GOTFORK);
	pthread_mutex_lock(philo->left_fork);
	ft_printer(philo, GOTFORK);
	ft_printer(philo, EATING);
	philo->meals_eaten++;
	philo->time_of_lm = ft_get_current_time();
	ft_usleep(philo->life->tteat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
