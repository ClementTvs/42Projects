/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:16:38 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/14 12:44:15 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/*
	is_sim_over - Check if the sim is over.

	This function reads the shared variable 'data->end_sim' safely using
	a mutex to avoid race conditions.It returns the current value of the simulation
	end state.

	@param data: Pointer to the struct that contains the shared data, including the
				 mutex and the simulation end flag.

	@return true if the simulation has ended, false otherwise.
*/
bool	is_sim_over(t_data *data)
{
	bool	res;

	pthread_mutex_lock(&data->sim_mutex);
	res = data->end_sim;
	pthread_mutex_unlock(&data->sim_mutex);
	return (res);
}

/*
	print_status - Print the status of a philosopher.

	This function gets the current time and prints the status message
	for the given philosopher. The printing is synchronized using a mutex
	to prevent output interleaving between threads.

	@param philo: Pointer to the philosopher whose status we want to print.
	@param status: The status message to display.
*/
void	print_status(t_philo *philo, char *status)
{
	long	current_time;

	current_time = get_time_in_ms() - philo->data->start_sim;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (!is_sim_over(philo->data))
		printf("%ld %d %s\n", current_time, philo->philo_id + 1, status);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	take_forks(t_philo *philo)
{
	int	first_fork_id;
	int	second_fork_id;
	t_fork	*first_fork;
	t_fork	*second_fork;

	first_fork_id = philo->lfork->fork_id;
	second_fork_id = philo->rfork->fork_id;
	first_fork = philo->lfork;
	second_fork = philo->rfork;
	if (philo->data->philo_nbr == 1)
    {
        pthread_mutex_lock(&philo->lfork->fork);
        print_status(philo, "has taken a fork");
        while (!is_sim_over(philo->data))
            usleep(1000);
        pthread_mutex_unlock(&philo->lfork->fork);
        return;
    }
	if (second_fork_id < first_fork_id)
	{
		first_fork = philo->rfork;
		second_fork = philo->lfork;
	}
	pthread_mutex_lock(&first_fork->fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&second_fork->fork);
	print_status(philo, "has taken a fork");
}

void	release_forks(t_philo *philo)
{
	int	first_fork_id;
	int	second_fork_id;
	t_fork	*first_fork;
	t_fork	*second_fork;

	first_fork_id = philo->lfork->fork_id;
	second_fork_id = philo->rfork->fork_id;
	first_fork = philo->lfork;
	second_fork = philo->rfork;
	if (second_fork_id < first_fork_id)
	{
		first_fork = philo->rfork;
		second_fork = philo->lfork;
	}
	pthread_mutex_unlock(&first_fork->fork);
	pthread_mutex_unlock(&second_fork->fork);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
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
	if (philo->philo_id % 2 == 0)
		usleep(5000);
	while(!is_sim_over(data))
	{
		print_status(philo, "is thinking");
		take_forks(philo);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal_time = get_time_in_ms();
		pthread_mutex_unlock(&philo->meal_mutex);
		print_status(philo, "is eating");
		precise_sleep(data->time_to_eat);
		philo->meals_count++;
		if (data->max_meals != -1 && philo->meals_count >= data->max_meals)
			philo->full = true;
		release_forks(philo);
		print_status(philo, "is sleeping");
		precise_sleep(data->time_to_sleep);
	}
	return (NULL);
}
