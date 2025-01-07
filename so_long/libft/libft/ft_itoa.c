/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:34:14 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:45:13 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	ft_intlen(int n)
{
	size_t	intlen;

	intlen = 0;
	if (n <= 0)
	{
		if (n == -2147483648)
		{
			return (11);
		}
		n *= -1;
		intlen++;
	}
	while (n >= 1)
	{
		n /= 10;
		intlen++;
	}
	return (intlen);
}

static char	*gogotransfo(char *str, long n, size_t len)
{
	int	negative;

	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (len - 1 > 0)
	{
		str[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (negative == 1)
		str[0] = '-';
	else
		str[0] = (n % 10) + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	str = 0;
	len = ft_intlen(n);
	str = gogotransfo(str, (long)n, len);
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = ft_itoa(-1);
	int	i = 0;

	while (str[i])
	{
		printf("%c", str[i]);
		i++;
	}
}*/
