/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:53:33 by ctravers          #+#    #+#             */
/*   Updated: 2024/11/11 11:53:37 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *n;

	n = malloc(sizeof(t_list));
	if (n == 0)
		return (0);
	n->content = content;
	n->next = NULL;
	return (n);
}
