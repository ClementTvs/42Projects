/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:36:08 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:44:17 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (nmemb > ((size_t) - 1) / size)
		return (0);
	tab = malloc(nmemb * size);
	if (tab == 0)
	{
		return (0);
	}
	ft_memset(tab, 0, nmemb * size);
	return (tab);
}
