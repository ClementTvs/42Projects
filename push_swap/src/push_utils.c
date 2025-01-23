/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:13:58 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/23 10:47:45 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_max(t_stack *stack)
{
	int	max;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	three_sort(t_stack **a)
{
	t_stack	*biggest_node;	

	biggest_node = find_max(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}
