/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:12:22 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 16:02:05 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* ************************************************************************* */
/*  ft_get_current_time                                                      */
/*                                                                           */
/*  Retrieves the current time in milliseconds since the Unix epoch using    */
/*  the gettimeofday function. If the retrieval fails, an error message is   */
/*  printed to standard error, and the function returns -1. Otherwise, it    */
/*  returns the time in milliseconds as a size_t value.                      */
/*                                                                           */
/*  Returns: The current time in milliseconds, or -1 if an error occurs.     */
/* ************************************************************************* */
size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday() error\n", 21);
		return (-1);
	}
	return ((size_t)(time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/* ************************************************************************* */
/*  ft_usleep                                                                */
/*                                                                           */
/*  Pauses the execution for the specified amount of milliseconds. It uses   */
/*  a loop to check the elapsed time and repeatedly calls usleep to ensure   */
/*  the program sleeps for the requested duration with high precision.       */
/*                                                                           */
/*  milliseconds: The amount of time, in milliseconds, for which the         */
/*                execution should be paused.                                */
/*                                                                           */
/*  Returns: 0 on completion.                                                */
/* ************************************************************************* */
int	ft_usleep(size_t milliseconds)
{
	size_t	begin_time;

	begin_time = ft_get_current_time();
	while ((ft_get_current_time() - begin_time) < milliseconds)
	{
		usleep(20000);
	}
	return (0);
}
