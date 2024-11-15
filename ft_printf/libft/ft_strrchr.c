/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:09:04 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/12 09:50:13 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char) c;
	while (str[i])
	{
		if ((unsigned char)str[i] == uc && ft_strrchr(str + i + 1, uc) == 0)
		{
			return (str + i);
		}
		i++;
	}
	if ((unsigned char)str[i] == uc)
		return (str + i);
	return (0);
}
