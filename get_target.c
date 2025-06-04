/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:03:41 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 10:03:42 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*closest_smaller(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*closest;
	long	closest_smaller;

	current = b;
	closest = NULL;
	closest_smaller = LONG_MIN;
	while (current)
	{
		if (current->num < a->num && current->num > closest_smaller)
		{
			closest_smaller = current->num;
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

static t_stack	*closest_bigger(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*closest;
	long	closest_bigger;

	current = a;
	closest = NULL;
	closest_bigger = LONG_MAX;
	while (current)
	{
		if (current->num > b->num && current->num < closest_bigger)
		{
			closest_bigger = current->num;
			closest = current;
		}
		current = current->next;
	}
	return (closest);
}

void	target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*current;
	long	max;

	while (a)
	{
		a->target = closest_smaller(a, b);
		if (a->target == NULL)
		{
			current = b;
			max = LONG_MIN;
			while (current)
			{
				if (current->num > max)
				{
					max = current->num;
					a->target = current;
				}
				current = current->next;
			}
		}
		a = a->next;
	}
}

void	target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*current;
	long	min;

	while (b)
	{
		b->target = closest_bigger(a, b);
		if (b->target == NULL)
		{
			current = a;
			min = LONG_MAX;
			while (current)
			{
				if (current->num < min)
				{
					min = current->num;
					b->target = current;
				}
				current = current->next;
			}
		}
		b = b->next;
	}
}
