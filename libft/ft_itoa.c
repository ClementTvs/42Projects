/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:34:14 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/08 08:25:01 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	intlen;

	intlen = 0;
	if (n < 0)
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

static char	*gogotransfo(char *str, int n, size_t len)
{
	int	negative;

	negative = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (n < 0)
	{
		if (n == -2147483648)
			return ("-2147483648");
		n *= -1;
		negative++;
	}
	str[len + 1] = '\0';
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
	str = gogotransfo(str, n, len);
	return (str);
}
