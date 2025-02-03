/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guest_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:18 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 11:14:05 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philo_routine(void *philo)
{
	t_philo	*guest;
	t_life *life;

	guest = (t_philo *)philo;
	life = guest->life;
	if (guest->id % 2 == 0)
		ft_usleep(100);
	while (1)
	{
		if (life->life_status != CONTINUE || guest->philo_status != PHILOSOPHING)
			break ;
		ft_eat(guest, life);
		if (life->life_status != CONTINUE || guest->philo_status != PHILOSOPHING)
			break ;
		ft_sleep(guest);
		if (life->life_status != CONTINUE || guest->philo_status != PHILOSOPHING)
			break ;
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
	if (philo->meals_eaten >= life->must_eat && life->must_eat != 0)
		philo->philo_status = FINISHED;
	philo->time_of_lm = ft_get_current_time();
	pthread_mutex_unlock(&life->eat);
	ft_usleep(life->tteat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
