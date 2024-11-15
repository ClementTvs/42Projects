/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:42:08 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/15 13:57:30 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_puthex(unsigned long num, char c)
{
	char *hexa_digits;
	
	if (c == 'X')
		hexa_digits = "0123456789ABCDEF";
	else
		hexa_digits = "0123456789abcdef";
	if (num >= 16)
		ft_puthex(num / 16, c);
	ft_putchar_fd(hexa_digits[num % 16], 1);
}

void	ft_putaddr(void *ptr)
{
	unsigned long addr = (unsigned long)ptr;

	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_puthex(addr, 'x');
}

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	int	div;
	int	mod;

	div = n / 10;
	mod = n % 10;
	if (n > 9)
	{
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

int	whatformat(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(((char)va_arg(args, int)), 1);
	if (c == 's')
		ft_putstr_fd((va_arg(args, char *)), 1);
	if (c == 'p')
		ft_putaddr(va_arg(args, void *));
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 'u')
		ft_putnbr_fd_unsigned(va_arg(args, unsigned int), 1);
	if (c == 'x')
		ft_puthex(va_arg(args, unsigned long), c);
	if (c == 'X')
		ft_puthex(va_arg(args, unsigned long), c);
	if (c == '%')
		ft_putchar_fd('%', 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i - 1] == '%' && format[i - 2] != '%')
		{
			whatformat(format[i], args);
		}
		else if (format[i] != '%')
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	//int x = 42;
	//int *ptr = &x;
	long	num = 4294967295;
	ft_printf("%u\n", (unsigned int)num);
	printf("%u\n", (unsigned int)num);
}*/
