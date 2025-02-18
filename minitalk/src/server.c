/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:55:45 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/18 11:15:34 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	handler(int signal, siginfo_t *info, void *more_info)
{
	(void)more_info;
	static char	c;
	static int	bit;
	static pid_t	client_pid;

	if (info->si_pid)
		client_pid = info->si_pid;

	if (SIGUSR1 == signal)
		c |= (0b10000000 >> bit);
	else if (SIGUSR2 == signal)
		c &= ~(0b10000000 >> bit);
	++bit;

	if (bit == 8)
	{
		bit = 0;

		if (c == '\0')
		{
			write(1, "\n", 1);
			Kill(client_pid, SIGUSR2);
			return ;
		}
		write(1, &c, 1);
	}
	Kill(client_pid, SIGUSR1);
}

int	main(void)
{
	ft_printf("PID:%d\n", getpid());

	Signal(SIGUSR1, handler, true);
	Signal(SIGUSR2, handler, true);

	while (1)
		pause();
	return (0);
}
