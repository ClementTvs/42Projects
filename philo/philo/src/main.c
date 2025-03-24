/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:12:19 by ctravers42        #+#    #+#             */
/*   Updated: 2025/03/23 17:14:50 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

bool	check_error(char **av, int ac)
{
	int	i;

	i = 1;
	if (ft_atoi(av[i]) > 200 || error_syntax(av[i]) || ft_atoi(av[i]) < 0)
		return (true);
	i++;
	while (i <= 4)
	{
		if (error_syntax(av[i]))
			return (true);
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < 60)
			return (true);
		i++;
	}
	if (ac == 6)
	{
		if (error_syntax(av[i]))
			return (true);
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < 0)
			return (true);
	}
	return (false);
}

void	start_sim(t_data *data)
{
	int	i;

	i = 0;
	data->start_sim = get_time_in_ms();
	while (i < data->philo_nbr)
	{
		if (safe_thread_create(&data->philos[i].thread_id, \
					philo_routine, &data->philos[i]))
		{
			return (err_msg("Error creating threads"));
		}
		i++;
	}
	i = 0;
	while (i < data->philo_nbr)
	{
		pthread_join(data->philos[i].thread_id, NULL);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data	*data;

	if ((ac != 5 && ac != 6) || check_error(av, ac))
		return (err_msg("Error, correct args would be : ./philo 5 100 800 600 [10]"), 1);
	else
	{
			data = init_sim(ac, av);
		if (!data)
			return (err_msg("Init failed"), 1);
		start_sim(data);
		free_data(data);
	}
	return (0);
}
