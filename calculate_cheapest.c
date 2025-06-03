/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cheapest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:48:54 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 13:18:05 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_total_costs(t_stack *stack)
{
	int	a_cost_abs;
	int	b_cost_abs;
	int	total_costs;

	if (stack->a_cost < 0)
		a_cost_abs = -stack->a_cost;
	else
		a_cost_abs = stack->a_cost;
	if (stack->b_cost < 0)
		b_cost_abs = -stack->b_cost;
	else
		b_cost_abs = stack->b_cost;
	total_costs = a_cost_abs + b_cost_abs;
	return (total_costs);
}

void	calculate_cost_a(t_stack *a, t_stack *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(a);
	length_b = stack_length(b);
	while (a)
	{
		if (a->index <= length_a / 2)
			a->a_cost = a->index;
		else
			a->a_cost = a->index - length_a;
		if (a->target)
		{
			if (a->target->index <= length_b / 2)
				a->b_cost = a->target->index;
			else
				a->b_cost = a->target->index - length_b;
		}
		else
			a->b_cost = 0;
		a->total_cost = calculate_total_costs(a);
		a = a->next;
	}
}

void	calculate_cost_b(t_stack *a, t_stack *b)
{
	int	length_a;
	int	length_b;

	length_a = stack_length(a);
	length_b = stack_length(b);
	while (b)
	{
		if (b->index <= length_b / 2)
			b->b_cost = b->index;
		else
			b->b_cost = b->index - length_b;
		if (b->target)
		{
			if (b->target->index <= length_a / 2)
				b->a_cost = b->target->index;
			else
				b->a_cost = b->target->index - length_a;
		}
		else
			b->a_cost = 0;
		b->total_cost = calculate_total_costs(b);
		b = b->next;
	}
}

t_stack	*calculate_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*current;

	if (!stack)
		return (NULL);
	cheapest = stack;
	current = stack;
	while (current)
	{
		if (current->total_cost < cheapest->total_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
