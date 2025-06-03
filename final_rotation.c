/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:04:33 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 11:05:27 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min(t_stack **a)
{
	t_stack	*min;
	t_stack	*current;

	if (!a || !*a)
		return (NULL);
	set_index(*a);
	min = *a;
	current = *a;
	while (current)
	{
		if (current->num < min->num)
			min = current;
		current = current->next;
	}
	return (min);
}

void	final_rotation(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(a);
	if (min->index <= stack_length(*a) / 2)
	{
		while (min->index > 0)
		{
			rotate_stack('a', a, b);
			min->index--;
		}
	}
	else
	{
		min->index = min->index - stack_length(*a);
		while (min->index < 0)
		{
			reverse_rotate_stack('a', a, b);
			min->index++;
		}
	}
}
