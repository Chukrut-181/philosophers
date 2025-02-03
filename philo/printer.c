/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:21:34 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 13:51:01 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printer(t_philo *philo, int k)
{
	size_t	time;
	t_life	*life;

	life = philo->life;
	pthread_mutex_lock(&philo->life->print);
	time = (ft_get_current_time() - philo->life->start_time);
	if (k == GOTFORK && life->status == CONTINUE)
		printf("%zu: Philosopher %i has taken a fork\n", time, philo->id);
	else if (k == EATING && life->status == CONTINUE)
		printf("%zu: Philosopher %i is eating\n", time, philo->id);
	else if (k == SLEEPING && life->status == CONTINUE)
		printf("%zu: Philosopher %i is sleeping\n", time, philo->id);
	else if (k == THINKING && life->status == CONTINUE)
		printf("%zu: Philosopher %i is thinking\n", time, philo->id);
	else if (k == DEAD)
		printf("%zu: Philosopher %i is dead\n", time, philo->id);
	pthread_mutex_unlock(&philo->life->print);
}
