/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers42 <ctravers@student.42perpignan.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:47:38 by ctravers42        #+#    #+#             */
/*   Updated: 2025/02/13 13:01:51 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Error in arguments, %c", av[1][0]);
		return (0);
	}
	return (0);
}
