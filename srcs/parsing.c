/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:43:07 by jskiba            #+#    #+#             */
/*   Updated: 2024/01/28 20:24:59 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(int nb)
{
	if (nb == 1)
		write (2, "La string est nulle\n", 21);
	if (nb == 2)
		write (2, "Le nombre est negatif\n", 22);
	if (nb == 3)
		write (2, "Le nombre est trop grand\n", 25);
	if (nb == 4)
		write (2, "il faut que des int\n", 22);
	exit (1);
}

long int	ft_atoi(char *str)
{
	int			a;
	int			b;
	long int	c;

	a = 0;
	b = 1;
	c = 0;
	if (!str || !*str)
		ft_error(1);
	while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
		a++;
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			ft_error(2);
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = c * 10 + (str[a] - '0');
		if (c * b > INT_MAX)
			ft_error(3);
		a++;
	}
	return (c);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nbphilo)
		pthread_mutex_init(&data->fork[i], NULL);
	i = -1;
	while (++i < data->nbphilo)
	{
		philo[i].name = i;
		philo[i].finisheat = get_time();
		philo[i].time = get_time();
		philo[i].nb_eat = 0;
		pthread_mutex_init(&philo[i].finish, NULL);
		if (i == data->nbphilo - 1)
			philo[i].right = &data ->fork[0];
		else
			philo[i].right = &data->fork[i + 1];
		philo[i].left = &data->fork[i];
		philo[i].data = data;
	}
}

void	parsing(t_data *data, char **av, int opt)
{
	t_philo		*philo;
	int			i;

	i = -1;
	pthread_mutex_init(& data->print, NULL);
	pthread_mutex_init(& data->die, NULL);
	pthread_mutex_init(& data->nbeatlock, NULL);
	data->dead = 0;
	data->nbphilo = ft_atoi(av[1]);
	data->tteat = ft_atoi(av[3]);
	data->ttdie = ft_atoi(av[2]);
	data->ttsleep = ft_atoi(av[4]);
	if (opt)
		data->nbeat = ft_atoi(av[5]);
	philo = malloc(sizeof(t_philo) * data->nbphilo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->nbphilo);
	init_philo(data, philo);
	data->philo = philo;
	while (++i < data->nbphilo)
		pthread_create(&philo[i].create, NULL, &routine, & data->philo[i]);
	i = -1;
	watcher(data);
	while (++i < data->nbphilo)
		pthread_join(philo[i].create, NULL);
}
