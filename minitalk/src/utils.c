/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:01:32 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/18 11:37:04 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	Kill(pid_t pid, int signal)
{
	if (kill(pid, signal) < 0)
	{
		ft_printf("Kill error");
		exit(0);
	}
}

void	Signal(int signal, void *handler, bool info)
{
	struct sigaction	sa = {0};

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
