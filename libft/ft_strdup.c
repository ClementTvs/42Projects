/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:55:10 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/04 16:06:45 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		taille;
	int		i;

	taille = ft_strlen(s);
	dest = malloc(taille * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		if (argc == 1)
			return (0);
		char	*dest = ft_strdup(argv[1]);
		if (dest == 0)
			return (0);
		printf("%s\n", dest);
		free(dest);
	}
}*/
