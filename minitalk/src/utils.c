/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:01:32 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/21 14:08:51 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	kill_mntlk(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		perror("Kill error");
		exit(EXIT_FAILURE);
	}
}

void	signal_mntlk(int signal, void *handler, bool info)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	if (info)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) < 0)
	{
		perror("sigaction failed");
		exit(EXIT_FAILURE);
	}
}
