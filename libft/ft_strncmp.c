/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:29:42 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/05 13:31:46 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cmp;

	cmp = 0;
	while ((s1[cmp] || s2[cmp]) && cmp < n)
	{
		if (s1[cmp] != s2[cmp])
			return (s1[cmp] - s2[cmp]);
		cmp++;
	}
	return (0);
}
