/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guest_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:18 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:00:27 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	ft_sleep(t_philo *philo)
{
	ft_printer(philo, SLEEPING);
	ft_usleep(philo->life->ttsleep);
}

void	ft_think(t_philo *philo)
{
	ft_printer(philo, THINKING);
}

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
