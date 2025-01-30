/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:18 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/30 10:42:34 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void	*ft_waiter_routine(void *philo)
{
// CHECK ALL ALIVE -- CHECK NOT FINISHED
	return (NULL);
} */

void	*ft_philo_routine(void *philo)
{
	t_philo	*guest;

	guest = (t_philo *)(philo);
	while (1)
	{
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
	ft_usleep(philo->life->tteat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
