/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:44:35 by jskiba            #+#    #+#             */
/*   Updated: 2024/01/28 19:44:49 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <pthread.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	long long		time;
	int				name;
	int				nb_eat;
	long long		finisheat;
	pthread_mutex_t	*left;
	pthread_mutex_t	finish;
	pthread_mutex_t	*right;
	pthread_t		create;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				ttsleep;
	int				tteat;
	int				nbphilo;
	int				ttdie;
	int				nbeat;
	int				dead;
	int				finish;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
	pthread_mutex_t	nbeatlock;
	t_philo			*philo;
}	t_data;

void		you_slip(long time);
int			ft_digit(char **av);
void		ft_dead(t_data *data, int i);
long int	get_time(void);
void		ft_unlock(t_philo *philo, int opt);
void		parsing(t_data *data, char **av, int opt);
long int	ft_atoi(char *str);
void		*routine(void *args);
int			print_msg(t_philo *philo, char *msg);
int			ft_sleep(t_philo *philo);
int			ft_eat(t_philo *philo);
void		ft_error(int nb);
void		watcher(t_data *data);

#endif