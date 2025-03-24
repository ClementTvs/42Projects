/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:24:25 by ctravers42        #+#    #+#             */
/*   Updated: 2025/03/23 17:15:39 by ctravers         ###   ########.fr       */
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

typedef pthread_mutex_t mtx_t;

typedef struct s_data t_data;

typedef struct s_fork
{
	mtx_t	fork;
	int	fork_id;
}			t_fork;

typedef struct s_philo
{
	int	philo_id;
	long	meals_count;
	bool	full;
	t_fork	*lfork;
	t_fork	*rfork;
	pthread_t	thread_id;
	t_data	*data;
} t_philo;

struct s_data
{
	int	philo_nbr;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
	long	start_sim;
	bool	end_sim;
	t_fork	*forks;
	t_philo	*philos;
};


void	err_msg(const char *str);
int	ft_atoi(const char *str);
bool	check_error(char **av, int ac);
int	error_syntax(char *str_n);
void	*safe_malloc(size_t bytes);
int	safe_mutex_init(mtx_t *mutex);
int	safe_thread_create(pthread_t *thread, void *(*routine)(void *), void *arg);
t_data	*init_sim(int ac, char **av);
t_data	*init_data(int ac, char **av);
t_philo	*init_philos(t_data *data);
t_fork	*init_forks(int philo_nbr);
void	free_data(t_data *data);
long	get_time_in_ms(void);
