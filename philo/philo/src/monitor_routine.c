/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:55:08 by ctravers          #+#    #+#             */
/*   Updated: 2025/05/07 18:55:10 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *monitor_routine(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;
    long current_time;
    long last_meal;
    bool all_full;
    bool full;

    while (1)
    {
        i = 0;
        all_full = true;
        while (i < data->philo_nbr)
        {
            pthread_mutex_lock(&data->philos[i].meal_mutex);
            last_meal = data->philos[i].last_meal_time;
            pthread_mutex_unlock(&data->philos[i].meal_mutex);
            full = data->philos[i].full;
            current_time = get_time_in_ms();
            if (!full && current_time - last_meal > data->time_to_die)
            {
				pthread_mutex_lock(&data->print_mutex);
                printf("%ld %d died\n", current_time - data->start_sim, data->philos[i].philo_id + 1);
                pthread_mutex_unlock(&data->print_mutex);
                pthread_mutex_lock(&data->sim_mutex);
                data->end_sim = true;
                pthread_mutex_unlock(&data->sim_mutex);
                return (NULL);
            }
            if (data->max_meals == -1 || !full)
                all_full = false;
            i++;
        }
        if (data->max_meals != -1 && all_full)
        {
            pthread_mutex_lock(&data->sim_mutex);
            data->end_sim = true;
            pthread_mutex_unlock(&data->sim_mutex);
            return (NULL);
        }
    }
    return (NULL);
}
