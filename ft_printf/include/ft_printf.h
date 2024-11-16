/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:44:19 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/16 11:19:23 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	whatformat(char c, va_list args);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putaddr(void *ptr);
int	ft_put_ptr(unsigned long num);
int	ft_puthex(unsigned int num, char c);
int	ft_putnbr(int n, int len);
int	ft_putstr(char *s);
int	ft_putchar(char c);

#endif
