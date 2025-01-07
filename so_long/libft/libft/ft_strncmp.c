/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:29:42 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:54:35 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h" 

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				cmp;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	cmp = 0;
	while ((str1[cmp] || str2[cmp]) && cmp < n)
	{
		if (str1[cmp] != str2[cmp])
			return (str1[cmp] - str2[cmp]);
		cmp++;
	}
	return (0);
}
