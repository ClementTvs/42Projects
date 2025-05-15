/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:38:51 by ctravers          #+#    #+#             */
/*   Updated: 2025/05/14 12:13:24 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = safe_malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->philo_nbr = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->max_meals = ft_atoi(av[5]);
	else
		data->max_meals = -1;
	data->end_sim = false;
	data->forks = NULL;
	data->philos = NULL;
	data->all_thread_rdy = false;
	safe_mutex_init(&data->print_mutex);
	safe_mutex_init(&data->sim_mutex);
	safe_mutex_init(&data->ready_mutex);
	return (data);
}

t_fork	*init_forks(int philo_nbr)
{
	t_fork	*forks;
	int		i;

	forks = safe_malloc(sizeof(t_fork) * philo_nbr);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < philo_nbr)
	{
		forks[i].fork_id = i;
		safe_mutex_init(&forks[i].fork);
		i++;
	}
	return (forks);
}

t_philo	*init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	philos = safe_malloc(sizeof(t_philo) * data->philo_nbr);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < data->philo_nbr)
	{
		philos[i].philo_id = i;
		philos[i].meals_count = 0;
		philos[i].full = false;
		philos[i].lfork = &data->forks[i];
		philos[i].rfork = &data->forks[(i + 1) % data->philo_nbr];
		philos[i].data = data;
		safe_mutex_init(&philos[i].meal_mutex);
		i++;
	}
	return (philos);
}

t_data	*init_sim(int ac, char **av)
{
	t_data	*data;

	data = init_data(ac, av);
	if (!data)
		return (NULL);
	data->forks = init_forks(data->philo_nbr);
	if (!data->forks)
		return (free_data(data), NULL);
	data->philos = init_philos(data);
	if (!data->philos)
		return (free_data(data), NULL);
	return (data);
}
