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

static t_stack *closest_smaller(t_stack *a, t_stack *b)
{
	t_stack	*current;
	long closest_smaller;

	current = b;
	closest_smaller = LONG_MIN;
	while (current)
	{
		if(current->num < a->num)
		closest = a;

	}
	return (closest);
}

static t_stack *closest_bigger()
{

}

void target_node_b(t_stack *a, t_stack *b)
{
    t_stack	*current;
    long	max;
    while (a)
    {
		a->target = closest_smaller();
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

void target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*current;
    long	min;

	while (b)
	{
		b->target = closest_bigger();
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