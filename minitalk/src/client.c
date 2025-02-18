/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:47:38 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/18 11:42:00 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t g_server = NOT_READY;

void	ok_handler()
{
	g_server = READY;
}

void	end_handler()
{
	write(1, "Message Received\n", 17);
	exit(0);
}

void	send_char(char c, pid_t server_pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0b10000000 >> bit))
			Kill(server_pid, SIGUSR1);
		else
			Kill(server_pid, SIGUSR2);
		++bit;
	}
	while (g_server == NOT_READY) 
		usleep(42);
	g_server = NOT_READY;
}

int	main(int ac, char **av)
{
	char	*message;
	pid_t	server_pid;

	if (ac != 3)
	{
		ft_printf("Error in arguments\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	message = av[2];

	Signal(SIGUSR1, ok_handler, false);
	Signal(SIGUSR2, end_handler, false);

	while (*message) 
		send_char(*message++, server_pid);
	send_char('\0', server_pid);
	return (0);
}
