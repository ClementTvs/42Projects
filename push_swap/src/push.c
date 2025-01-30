/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:38:23 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/30 11:22:00 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **sender, t_stack **receiver)
{
	t_stack	*temp;

	if (!*sender)
		return ;
	temp = *sender;
	*sender = (*sender)->next;
	if (*sender)
		(*sender)->prev = NULL;
	temp->prev = NULL;
	if (!*receiver)
	{
		*receiver = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *receiver;
		if (temp->next)
			temp->next->prev = temp;
		*receiver = temp;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}
