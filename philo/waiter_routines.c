/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiter_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:17:44 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 10:56:34 by igchurru         ###   ########.fr       */
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
		if ((ft_get_current_time() - philo[i].time_of_lm) > life->ttdie)
		{
			pthread_mutex_lock(&life->waiter);
			life->life_status = STOP;
			philo[i].philo_status = DEAD;
			pthread_mutex_unlock(&life->waiter);
			ft_printer(&philo[i], DEAD);
			return (1);
		}
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
		if (philo[i].philo_status == PHILOSOPHING)
			return (0);
		i++;
	}
	return (1);
}
