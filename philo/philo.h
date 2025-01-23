/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:11:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/23 15:25:26 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct philo
{
	int	number;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	must_eat;
}	t_philo;

//	MAIN
int		main(int argc, char **argv);

//	PARSE
int		**ft_parse_argv(int argc, char **argv);

//	UTILS
int		ft_atoi(const char *str);

//	(DEBUG FTs TO BE REMOVED)
void	ft_checkprinter(int argc, int **array);

#endif
