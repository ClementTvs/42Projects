/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:17:42 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/13 11:33:41 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include "../ft_printf/include/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

void	handler(int signal, siginfo_t *info, void *more_info);
void    Signal(int signal, void *handler, bool info);

#endif
