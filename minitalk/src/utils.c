/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:01:32 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/18 13:55:14 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	kill_mntlk(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_printf("Kill error");
		exit(0);
	}
}

void	signal_mntlk(int signal, void *handler, bool info)
{
	struct sigaction	sa;

	sa = {0};
	if (info)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(signal, &sa, NULL) > 0)
	{
		ft_printf("sigaction failed");
		exit(0);
	}
}
