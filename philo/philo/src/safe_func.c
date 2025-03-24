/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:22:03 by ctravers          #+#    #+#             */
/*   Updated: 2025/03/21 11:59:14 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ptr;

	ptr = malloc(bytes);
	if (!ptr)
	{
		err_msg("Malloc failed\n");
		return (NULL);
	}
	return (ptr);
}

int	safe_mutex_init(mtx_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		err_msg("Mutex init failed\n");
		return (-1);
	}
	return (0);
}

int	safe_thread_create(pthread_t *thread, void *(*routine)(void *), void *arg)
{
	if (pthread_create(thread, NULL, routine, arg) != 0)
	{
		err_msg("Thread creation failed\n");
		return (-1);
	}
	return (0);
}
