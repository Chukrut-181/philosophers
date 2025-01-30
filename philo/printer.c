/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:21:34 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/30 11:12:10 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printer(t_philo *philo, int k)
{
	double	time;

	pthread_mutex_lock(&philo->life->print);
	time = (double)(ft_get_current_time() - philo->life->start_time) / 1000;
	if (k == GOTFORK)
		printf("%.3f: Philosopher %i has taken a fork\n", time, philo->id);
	else if (k == EATING)
		printf("%.3f: Philosopher %i is eating\n", time, philo->id);
	else if (k == SLEEPING)
		printf("%.3f: Philosopher %i is sleeping\n", time, philo->id);
	else if (k == THINKING)
		printf("%.3f: Philosopher %i is thinking\n", time, philo->id);
	else if (k == DEAD)
		printf("%.3f: Philosopher %i is dead\n", time, philo->id);
	pthread_mutex_unlock(&philo->life->print);
}
