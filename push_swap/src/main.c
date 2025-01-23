/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:46:02 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/22 11:17:45 by ctravers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*get_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	add_node(t_stack **stack, int nb)
{
	t_stack	*new;
	t_stack	*last;

	new = malloc(sizeof(t_stack));
	if (!new)
		return;
	new->nb = nb;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else

	{
		last = get_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

int	is_it_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
//	t_stack	*b;
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	if (argc < 2)
	{
		ft_printf("You need to put at least 2 arguments\n");
		return (0);
	}
	a = NULL;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		add_node(&a, nb);
		//ft_printf("%i\n", a->nb);
		//a = a->next;
		i++;
	}
	if (is_it_sorted(a))
		ft_printf("Sorted\n");
	else
	{
		if (argc == 3)
		{
			ra(&a);
			ft_printf("%i, %i\n", a->nb, a->next->nb);
		}
		else if (argc == 4)
		{
			three_sort(&a);
			ft_printf("%i, %i, %i\n", a->nb, a->next->nb, a->next->next->nb);
		}
		if (is_it_sorted(a))
			ft_printf("Sorteeeed\n");
	}
}
