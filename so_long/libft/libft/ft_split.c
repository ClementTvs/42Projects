/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:09:47 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:52:33 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static	size_t	wordcnt(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	if (i == ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i + 1] == c && s[i + 1] != '\0')
			j++;
		if (s[i + 1] == '\0' && s[i] != c)
			j++;
		if (s[i])
			i++;
	}
	return (j);
}

static int	allocsstr(size_t i, char **sstr, size_t cmp)
{
	size_t	j;

	j = 0;
	sstr[i] = malloc(sizeof(char) * (cmp + 1));
	if (sstr[i] == 0)
	{
		while (j < i)
		{
			free(sstr[j]);
			j++;
		}
		free(sstr);
		return (0);
	}
	return (1);
}

static int	memalloc(char **sstr, char c, char const *s)
{
	size_t	cmp;
	size_t	i;
	size_t	j;

	cmp = 0;
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
			cmp++;
		else if (j > 0 && s[j - 1] != c)
		{
			if (!allocsstr(i, sstr, cmp))
				return (0);
			cmp = 0;
			i++;
		}
		if (s[j + 1] == '\0' && s[j] != c)
			if (!(allocsstr(i, sstr, cmp)))
				return (0);
		j++;
	}
	return (1);
}

static char	**fill(char **sstr, char c, const char *s)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] != c)
			sstr[x][j++] = s[i];
		else if (i > 0 && s[i - 1] != c)
		{
			sstr[x][j] = '\0';
			j = 0;
			x++;
		}
		if (s[i + 1] == '\0' && s[i] != c)
			sstr[x][j] = '\0';
		i++;
	}
	return (sstr);
}

char	**ft_split(char const *s, char c)
{
	char	**sstr;
	size_t	wordcount;

	if (!s || !*s)
	{
		sstr = malloc(sizeof(char *) * 1);
		if (sstr == 0)
			return (0);
		*sstr = 0;
		return (sstr);
	}
	wordcount = wordcnt(s, c);
	sstr = malloc(sizeof(char *) * (wordcount + 1));
	if (sstr == 0)
		return (0);
	if (!memalloc(sstr, c, s))
		return (0);
	fill(sstr, c, s);
	sstr[wordcount] = NULL;
	return (sstr);
}
/*
#include <stdio.h>
int	main(void)
{
	char **result = ft_split("hello!", ' ');
	size_t	i = 0;

	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
    if (result != NULL)
    {
        for (size_t i = 0; result[i] != NULL; i++)
        {
            free(result[i]);
        }
        free(result);
    }
    return 0;
}*/
