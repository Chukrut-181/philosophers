/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:46:26 by igchurru          #+#    #+#             */
/*   Updated: 2025/02/03 15:25:04 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = (sign * -1);
			str++;
		}
		else
			str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

/* ************************************************************************* */
/*  ft_memset                                                                */
/*                                                                           */
/*  Sets the first 'len' bytes of the memory area pointed to by 'b' to the   */
/*  specified value 'c', interpreted as an unsigned char. This function is   */
/*  typically used for initializing memory.                                  */
/*                                                                           */
/*  b: Pointer to the memory area to be set.                                 */
/*  c: The value to set each byte to.                                        */
/*  len: The number of bytes to set.                                         */
/*                                                                           */
/*  Returns: The pointer to the memory area 'b'.                             */
/* ************************************************************************* */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (0 < len)
	{
		*p = (unsigned char)c;
		p++;
		len--;
	}
	return (b);
}

/* ************************************************************************* */
/*  ft_dinnerforone                                                          */
/*                                                                           */
/*  Handles the special case where there is only one philosopher. The        */
/*  philosopher immediately picks up a fork, then simulates eating and       */
/*  dying (since they cannot eat without a partner).                         */
/*                                                                           */
/*  philo: Pointer to the philosopher structure for the solo philosopher.    */
/*                                                                           */
/*  Returns: None.                                                           */
/* ************************************************************************* */
void	ft_dinnerforone(t_philo *philo)
{
	ft_printer(philo, GOTFORK);
	ft_usleep(philo->life->ttdie);
	ft_printer(philo, DEAD);
}
