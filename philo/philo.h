/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:11:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 10:12:22 by igchurru         ###   ########.fr       */
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

# define MAXPHILOS 250

//	PHILOSOPHERS DATA
typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	size_t			time_of_lm;
	int				meals_eaten;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				isdead;
}	t_philo;

//	COMMON DATA
typedef struct s_life
{
	int			number_of_philos;
	int			ttdie;
	int			tteat;
	int			ttsleep;
	int			must_eat;
}	t_life;

//	MAIN
int		main(int argc, char **argv);
void	ft_initphilos(char **av, t_philo *philo, pthread_mutex_t *fork);
void	ft_initlife(int argc, char **argv, t_life *life);

//	PARSE
int		ft_check_args(int argc, char **argv);

//	UTILS
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);

//	TIME
ssize_t	ft_get_current_time(void);

//	(DEBUG AND TEST FTs TO BE REMOVED)
void	ft_checkprinter(int argc, int **array);
void	*routine(void *arg);

#endif
