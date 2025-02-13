/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:53:09 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/12 09:48:53 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	unsigned char	uc;
	int				i;

	i = 0;
	uc = (unsigned char) c;
	while (str[i])
	{
		if ((unsigned char)str[i] == uc)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if ((unsigned char)str[i] == uc)
		return ((char *)str + i);
	return (0);
}
