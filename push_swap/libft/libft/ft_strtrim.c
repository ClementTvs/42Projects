/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:49:33 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:55:18 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

//Verifie si le char c est dans le set, si oui alors return 0, sinon return 1.
static int	in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

//Supprime dans s1 les caracteres de debuts et de fins qui sont dans set.
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bgn;
	size_t	end;
	char	*s1c;

	bgn = 0;
	end = ft_strlen(s1);
	while (in_set(s1[bgn], set) == 0)
		bgn++;
	if (bgn == ft_strlen(s1))
	{
		s1c = ft_strdup("");
		if (!s1c)
			return (0);
		else
			return (s1c);
	}
	while (in_set(s1[end - 1], set) == 0)
		end--;
	s1c = ft_substr(s1, bgn, end - bgn);
	return (s1c);
}
