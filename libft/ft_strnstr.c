/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:32:50 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/05 14:44:11 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (i < len - 1)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (j == ft_strlen(little))
			{
				return ((char *)big + i);
			}
		}
		i++;
	}
	return (0);
}

#include <stdio.h>
int	main()
{
	const char	*big = "Salut je marche ou pas ?";
	const char	*little = "?";

	char	*res = ft_strnstr(big, little, 24);

	printf("%s", res);
}
