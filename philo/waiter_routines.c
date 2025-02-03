/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:17:44 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:06:22 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
