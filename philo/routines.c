/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:19:18 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 15:37:44 by igchurru         ###   ########.fr       */
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
	

//	ESTABLISH ROUTINES
	//	EAT
	ft_sleep(guest);
	ft_think(guest);
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
