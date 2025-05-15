/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:26:34 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/07 17:31:59 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	signe;

	a = 0;
	i = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		a = a * 10 + (str[i] - 48);
		i++;
	}
	return (a * signe);
}

void	err_msg(const char *str)
{
	printf(RED "%s\n" RST, str);
}

void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	if (data->forks)
	{
		while (i < data->philo_nbr)
			pthread_mutex_destroy(&data->forks[i++].fork);
		free(data->forks);
	}
	if (data->philos)
	{
		i = 0;
		while (i < data->philo_nbr)
			pthread_mutex_destroy(&data->philos[i++].meal_mutex);
		free(data->philos);
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->sim_mutex);
	free(data);
}

void	sync_philos(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->ready_mutex);
		if (data->all_thread_rdy)
		{
			pthread_mutex_unlock(&data->ready_mutex);
			break ;
		}
		pthread_mutex_unlock(&data->ready_mutex);
		usleep(10 * data->philo_nbr / 2);
	}
}
