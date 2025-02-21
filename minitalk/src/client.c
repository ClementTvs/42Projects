/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:47:38 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/21 14:11:15 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t	g_server = NOT_READY;

void	ok_handler(void)
{
	g_server = READY;
}

void	end_handler(void)
{
	write(1, "Message Received\n", 17);
	exit(EXIT_SUCCESS);
}

void	send_char(char c, pid_t server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0b10000000 >> bit))
			kill_mntlk(server_pid, SIGUSR1);
		else
			kill_mntlk(server_pid, SIGUSR2);
		++bit;
		while (g_server == NOT_READY)
			usleep(42);
		g_server = NOT_READY;
	}
}

int	main(int ac, char **av)
{
	char	*message;
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_printf("Error in arguments\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(av[1]);
	message = av[2];
	signal_mntlk(SIGUSR1, ok_handler, false);
	signal_mntlk(SIGUSR2, end_handler, false);
	while (*message)
		send_char(*message++, server_pid);
	send_char('\0', server_pid);
	return (0);
}
