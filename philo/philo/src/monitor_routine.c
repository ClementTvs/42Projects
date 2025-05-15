/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:55:08 by ctravers          #+#    #+#             */
/*   Updated: 2025/05/14 13:31:38 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static bool	check_death(int i, bool *all_full, t_data *data)
{
	long	current_time;
	bool	full;
	long	last_meal;

	pthread_mutex_lock(&data->philos[i].meal_mutex);
	last_meal = data->philos[i].last_meal_time;
	pthread_mutex_unlock(&data->philos[i].meal_mutex);
	full = data->philos[i].full;
	current_time = get_time_in_ms();
	if (!full && current_time - last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&data->print_mutex);
		printf("%ld %d died\n", current_time - data->start_sim,
			data->philos[i].philo_id + 1);
		pthread_mutex_unlock(&data->print_mutex);
		pthread_mutex_lock(&data->sim_mutex);
		data->end_sim = true;
		pthread_mutex_unlock(&data->sim_mutex);
		return (true);
	}
	if (data->max_meals == -1 || !full)
		*all_full = false;
	return (false);
}

static bool	check_full(t_data *data, bool all_full)
{
	if (data->max_meals != -1 && all_full)
	{
		pthread_mutex_lock(&data->sim_mutex);
		data->end_sim = true;
		pthread_mutex_unlock(&data->sim_mutex);
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	bool	all_full;

	data = (t_data *)arg;
	sync_philos(data);
	while (1)
	{
		i = 0;
		all_full = true;
		while (i < data->philo_nbr)
		{
			if (check_death(i++, &all_full, data))
				return (NULL);
		}
		if (check_full(data, all_full))
			return (NULL);
		usleep(5000);
	}
	return (NULL);
}
