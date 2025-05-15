/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:24:25 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/14 12:13:03 by ctravers42       ###   ########.fr       */
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

/*
This struct contains:
	A mutex fork
	The id of the fork
*/
typedef struct s_fork
{
	mtx_t	fork;
	int	fork_id;
}			t_fork;

/*
This struct contains :
	The ID of the philo
	The nbr of meals they ate
	A bool to know if they are full
	The last time they got a meal
	A fork to the left fork
	A fork to the right fork
	The ID of the thread
	And the data struct
	*/
typedef struct s_philo
{
	int	philo_id;
	long	meals_count;
	bool	full;
	long	last_meal_time;
	t_fork	*lfork;
	t_fork	*rfork;
	mtx_t	meal_mutex;
	pthread_t	thread_id;
	t_data	*data;
} t_philo;

/*
This struct contains :
	The number of philosophers
	The time to die
	The time to eat
	The time to sleep
	The max amount of meal they can get
	A start sim long ->Idk why
	An end sim bool to know when to end the sim
	A sim mutex to protect sim data
	A print mutex to protect the sim printf
	The forks and philos struct
*/
struct s_data
{
	int	philo_nbr;
	long	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_meals;
	long	start_sim;
	bool	end_sim;
	mtx_t	sim_mutex;
	mtx_t	print_mutex;
	mtx_t	ready_mutex;
	bool	all_thread_rdy;
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
void	precise_sleep(long ms);
void	*philo_routine(void *arg);
void	release_forks(t_philo *philo);
void	take_forks(t_philo *philo);
void	print_status(t_philo *philo, char *status);
bool	is_sim_over(t_data *data);
void    *monitor_routine(void *arg);
void	sync_philos(t_data *data);

