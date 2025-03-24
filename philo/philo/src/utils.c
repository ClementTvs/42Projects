/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:26:34 by ctravers42        #+#    #+#             */
/*   Updated: 2025/03/21 12:44:01 by ctravers         ###   ########.fr       */
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
	if (!data)
		return ;
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->philo_nbr)
		{
			pthread_mutex_destroy(&data->forks[i].fork);
			i++;
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	free(data);
}

