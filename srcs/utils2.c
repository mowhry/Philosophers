/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jskiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:44:07 by jskiba            #+#    #+#             */
/*   Updated: 2024/01/28 20:24:48 by jskiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_dead(t_data *data, int i)
{
	pthread_mutex_lock(& data->die);
	data->dead = 1;
	pthread_mutex_unlock(& data->die);
	pthread_mutex_lock(&data->print);
	printf("%lld %d Died\n", (get_time() - data->philo[i].time),
		data->philo->name + 1);
	pthread_mutex_unlock(&data->print);
}

void	ft_unlock(t_philo *philo, int opt)
{
	if (opt == 0)
		pthread_mutex_unlock(philo->right);
	else if (opt == 1)
		pthread_mutex_unlock(philo->left);
	else
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
	}
}

int	ft_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
		}
		i++;
	}
	return (0);
}
