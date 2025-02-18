/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:17:42 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/18 13:55:43 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include "../ft_printf/include/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

enum
{
	READY,
	NOT_READY
};

void	handler(int signal, siginfo_t *info);
void	signal_mntlk(int signal, void *handler, bool info);
void	kill_mntlk(pid_t pid, int signal);
int		ft_atoi(const char *str);

#endif
