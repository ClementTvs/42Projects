/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:13:31 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:49:41 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				cmp;

	cmp = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (cmp < n)
	{
		if (p1[cmp] != p2[cmp])
			return (p1[cmp] - p2[cmp]);
		cmp++;
	}
	return (0);
}
