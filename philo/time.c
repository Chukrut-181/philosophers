/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:12:22 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 10:56:34 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ssize_t	ft_get_current_time(void)
{
	struct timeval	time;
	size_t			clock;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 21);
		return (-1);
	}
	clock = ((time.tv_sec * 1000) + (time.tv_usec / 1000));
	return (clock);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	begin_time;

	begin_time = ft_get_current_time();
	while ((ft_get_current_time() - begin_time) < milliseconds)
	{
		usleep(500);
	}
	return (0);
}
