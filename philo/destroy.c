/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:29:15 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:07:30 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
}

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
