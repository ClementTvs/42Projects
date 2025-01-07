/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:15:34 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:59:02 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *str, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char) c;
	while (str[i])
	{
		if ((unsigned char)str[i] == uc)
		{
			return (1);
		}
		i++;
	}
	if ((unsigned char)str[i] == uc)
		return (1);
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == src)
		return (dest);
	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
		return (dest);
	}
	i = n;
	while (i > 0)
	{
		d[i - 1] = s[i - 1];
		i--;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	if (!temp)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (temp);
}
