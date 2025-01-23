/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:07:24 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:53:21 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	lentot;
	char	*strr;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return ((char *)s2);
	else if (s2 == 0)
		return ((char *)s1);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	lentot = lens1 + lens2;
	strr = malloc((lentot + 1) * sizeof(char));
	if (strr == 0)
		return (0);
	ft_memmove(strr, s1, lens1);
	ft_memmove(strr + lens1, s2, lens2);
	strr[lentot] = '\0';
	return (strr);
}
