/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:08 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/16 11:17:20 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_put_ptr(unsigned long num)
{
	int		len;
	char	*hexa_digits;

	len = 0;
	hexa_digits = "0123456789abcdef";
	if (num >= 16)
		len += ft_put_ptr(num / 16);
	len += ft_putchar(hexa_digits[num % 16]);
	return (len);
}

int	ft_putaddr(void *ptr)
{
	unsigned long	addr;
	int				len;

	len = 0;
	addr = (unsigned long)ptr;
	if (addr == 0)
	{
		len += ft_putstr("(nil)");
		return (len);
	}
	len += ft_putchar('0');
	len += ft_putchar('x');
	len += ft_put_ptr(addr);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	div;
	int	mod;
	int	len;

	div = n / 10;
	mod = n % 10;
	len = 0;
	if (n > 9)
	{
		len += ft_putnbr_unsigned(div);
		len += ft_putnbr_unsigned(mod);
	}
	else
	{
		ft_putchar(n + 48);
		len++;
	}
	return (len);
}

int	whatformat(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(((char)va_arg(args, int)));
	if (c == 's')
		len += ft_putstr((va_arg(args, char *)));
	if (c == 'p')
		len += ft_putaddr(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int), len);
	if (c == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned int));
	if (c == 'x')
		len += ft_puthex(va_arg(args, unsigned int), c);
	if (c == 'X')
		len += ft_puthex(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += whatformat(format[i + 1], args);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
#include <stdio.h>
int	main()
{
	int x;
	//int *ptr = &x;
	x = ft_printf(" %x ", LONG_MAX);
	printf("%i", x);
	x = printf(" %lx ", LONG_MAX);
	printf("%i", x);
}*/
