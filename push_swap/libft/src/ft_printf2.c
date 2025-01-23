/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:15:50 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/16 11:20:02 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n, int len)
{
	if (n == -2147483648)
	{
		len += 11;
		ft_putstr("-2147483648");
		return (len);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		len++;
		n *= -1;
		len += ft_putnbr(n, 0);
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10, 0);
		len += ft_putnbr(n % 10, 0);
	}
	else
	{
		ft_putchar(n + 48);
		len++;
	}
	return (len);
}

int	ft_puthex(unsigned int num, char c)
{
	char	*hexa_digits;
	int		len;

	len = 0;
	if (c == 'X')
		hexa_digits = "0123456789ABCDEF";
	else
		hexa_digits = "0123456789abcdef";
	if (num >= 16)
		len += ft_puthex(num / 16, c);
	len += ft_putchar(hexa_digits[num % 16]);
	return (len);
}
