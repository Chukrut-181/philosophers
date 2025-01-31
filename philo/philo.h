/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:11:24 by igchurru          #+#    #+#             */
/*   Updated: 2025/01/31 13:01:38 by igchurru         ###   ########.fr       */
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
# define PHILOSOPHING 6
# define FINISHED 7
# define DEAD 8

//	PHILOSOPHERS DATA
typedef struct s_philosopher
{
	pthread_t		thread;
	int				id;
	size_t			time_of_lm;
	int				meals_eaten;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int				philo_status;
	struct s_life	*life;
}	t_philo;

//	COMMON DATA
typedef struct s_life
{
	int				number_of_philos;
	int				life_status;
	size_t			start_time;
	size_t			ttdie;
	size_t			tteat;
	size_t			ttsleep;
	int				must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
}	t_life;

//	MAIN
int		main(int argc, char **argv);
void	ft_initforks(pthread_mutex_t *forks);
void	ft_initphilos(char **av, t_philo *philo,
			pthread_mutex_t *fork, t_life *life);
void	ft_initlife(int argc, char **argv, t_life *life);
void	ft_init_threads(t_philo *philo, t_life *life);

//	PARSE
int		ft_check_args(int argc, char **argv);

//	GUEST ROUTINES
void	*ft_philo_routine(void *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_eat(t_philo *philo);

//	WAITER ROUTINES
void	*ft_waiter_routine(void *philo);
int		ft_check_for_corpses(t_philo *philo, t_life *life);
int		ft_check_for_end(t_philo *philo, t_life *life);

//	UTILS
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_dinnerforone(t_philo *philo);

//	TIME
ssize_t	ft_get_current_time(void);
int		ft_usleep(size_t milliseconds);

// 	PRINTER
void	ft_printer(t_philo *philo, int k);

//	DESTROY
void	ft_destroy_mutexes(t_life *life, pthread_mutex_t *forks);

//	(DEBUG AND TEST FTs TO BE REMOVED)
void	ft_checkprinter(int argc, int **array);

#endif
