/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:32:50 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:54:50 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!little[0])
		return ((char *)big);
	if (len == 0)
		return (0);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j])
		{
			j++;
			if (j == ft_strlen(little))
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
