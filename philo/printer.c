/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:21:34 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 14:02:25 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printer(t_philo *philo, int k)
{
	ssize_t	time;
	
	pthread_mutex_lock(&philo->life->print);
	time = ft_get_current_time() - philo->life->start_time;
	if (k == 2)
		printf("%zu: Philosopher %i has taken a fork\n", time, philo->id);
	else if (k == 4)
		printf("%zu: Philosopher %i is sleeping\n", time, philo->id);
	pthread_mutex_unlock(&philo->life->print);
}
