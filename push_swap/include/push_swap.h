/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctravers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:43:25 by ctravers          #+#    #+#             */
/*   Updated: 2025/01/30 11:31:09 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				nb;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
}	t_stack;

t_stack	*get_last_node(t_stack *stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	push(t_stack **sender, t_stack **receiver);
void	add_node(t_stack **stack, int nb);
int		is_it_sorted(t_stack *stack);
t_stack	*find_max(t_stack *stack);
void	three_sort(t_stack **a);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	sort_stack(t_stack **a, t_stack **b);
int		stack_len(t_stack *stack);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
t_stack	*get_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	sort_stack(t_stack **a, t_stack **b);
t_stack	*find_min(t_stack *stack);
void	init_nodes_b(t_stack *a, t_stack *b);
t_stack	*find_last(t_stack *stack);
int		error_syntax(char *str_n);
int		error_duplicate(t_stack *a, int n);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **a);
void	init_stack_a(t_stack **a, char *argv[]);
char	**split(char *s, char c);

#endif
