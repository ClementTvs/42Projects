/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:45 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/13 11:36:07 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signal, siginfo_t *info, void *more_info)
{
	(void)signal;
	(void)info;
	(void)more_info;

	ft_printf("Bonjour");
}

int	main(void)
{
	ft_printf("Bonjour PID:%d\n", getpid());

	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);

	while (1)
		pause();
	return (0);
}
