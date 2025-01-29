/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:11:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/29 15:47:32 by igchurru         ###   ########.fr       */
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

# define CONTINUE 0
# define STOP 1
# define GOTFORK 2
# define EATING 3
# define SLEEPING 4
# define THINKING 5

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
	struct s_life	*life;
}	t_philo;

//	COMMON DATA
typedef struct s_life
{
	int				number_of_philos;
	size_t			start_time;
	size_t			ttdie;
	size_t			tteat;
	size_t			ttsleep;
	size_t			must_eat;
	pthread_mutex_t	print;
}	t_life;

//	MAIN
int		main(int argc, char **argv);
void	ft_initphilos(char **av, t_philo *philo,
			pthread_mutex_t *fork, t_life *life);
void	ft_initlife(int argc, char **argv, t_life *life);
void	ft_init_threads(t_philo *philo, t_life *life);

//	PARSE
int		ft_check_args(int argc, char **argv);

//	ROUTINES
//void	*ft_waiter_routine(void *philo);
void	*ft_philo_routine(void *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

//	UTILS
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);

//	TIME
ssize_t	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);

// 	PRINTER
void	ft_printer(t_philo *philo, int k);

//	(DEBUG AND TEST FTs TO BE REMOVED)
void	ft_checkprinter(int argc, int **array);
void	*routine(void *arg);

#endif
