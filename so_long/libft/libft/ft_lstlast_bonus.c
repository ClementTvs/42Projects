/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <ctravers@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:25:03 by ctravers          #+#    #+#             */
/*   Updated: 2024/12/19 09:47:45 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int	main()
{
	t_list n, n1, n2;
	n.content = malloc(sizeof(int));
    	n1.content = malloc(sizeof(int));
    	n2.content = malloc(sizeof(int));

	*(int *)n.content = 45;
	*(int *)n1.content = 42;
	*(int *)n2.content = 23;

	n.next = &n1;
	n1.next = &n2;
	n2.next = NULL;
	ft_lstlast(&n);
}*/
