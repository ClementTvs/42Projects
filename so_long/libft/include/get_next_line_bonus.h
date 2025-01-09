/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:14:36 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/09 10:34:53 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_memmove_gnl(void *dest, const void *src, size_t n);
int		ft_strchr_gnl(const char *str, int c);
int		ft_strlen_gnl(char *str);

#endif
