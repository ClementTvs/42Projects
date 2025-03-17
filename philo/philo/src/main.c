/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:12:19 by ctravers42        #+#    #+#             */
/*   Updated: 2025/03/17 11:32:06 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

bool	check_error(char **av)
{
	int	i;

	i = 1;
	if (ft_atoi(av[i]) > 200 && !error_syntax(av[i]))
		return (true);
	i++;
	while(av[i])
	{
		if (error_syntax(av[i]))
			return (true);
		if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < 0)
			return (true);
		i++;
	}
	return (false);
}

void	init_philo(char **av, int ac, t_philo *philo)
{
	philo->nbr = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo->eat_max = ft_atoi(av[5]);
	else
		philo->eat_max = -1;
}

int	main(int ac, char **av)
{
	t_philo	philo;

	if ((ac != 5 && ac != 6) || check_error(av))
	{
		err_msg("Error, correct args would be : ./philo 5 100 800 600 [10]");
		return (0);
	}
	else
	{
		init_philo(av, ac, &philo);
	}
	return (0);
}
