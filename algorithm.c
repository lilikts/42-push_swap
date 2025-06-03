/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:04:49 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 13:49:05 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	index;

	index = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_length(*a) > 3)
		push_stack('b', a, b);
	if (stack_length(*a) > 3)
		push_stack('b', a, b);
	while (stack_length(*a) > 3)
	{
		set_index(*a);
		set_index(*b);
		target_node_b(*a, *b);
		execute_cheapest_move_a(a, b);
	}
	sort_three(a);
	while (*b != NULL)
	{
		set_index(*a);
		set_index(*b);
		target_node_a(*a, *b);
		execute_cheapest_move_b(a, b);
	}
	final_rotation(a, b);
}
