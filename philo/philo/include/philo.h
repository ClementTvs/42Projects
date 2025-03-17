/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:24:25 by ctravers42        #+#    #+#             */
/*   Updated: 2025/03/17 11:05:13 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

#define RED "\033[1;91m"
#define GREEN "\033[1;92m"
#define RST "\033[0m"

typedef struct s_philo
{
	int	nbr;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_max;
} t_philo;


void	err_msg(const char *str);
int	ft_atoi(const char *str);
bool	check_error(char **av);
int	error_syntax(char *str_n);
