/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:19:03 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/22 10:07:38 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*goodline(char *buffer);
char	*deldoneline(char *buffer);
void	*free_memory(char *buffer, char *res);
char	*readfile(int fd, char *res, ssize_t readb);
char	*ft_free(char *buffer, char *buf);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strchr(const char *str, int c);
int		ft_strlen(char *str);

#endif
