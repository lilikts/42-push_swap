/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 13:40:38 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 13:48:49 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	long	first;
	long	second;

	first = (*a)->num;
	second = (*a)->next->num;
	if (first < second)
		return ;
	else
		swap_stack('a', a, NULL);
}

static void	exec_moves(t_stack **a, long first, long second, long third)
{
	t_stack	**b;

	b = NULL;
	if (first < second && second < third)
		return ;
	else if (first < second && second > third && first < third)
	{
		swap_stack('a', a, b);
		rotate_stack('a', a, b);
	}
	else if (first > second && second < third && first < third)
		swap_stack('a', a, b);
	else if (first < second && second > third && first > third)
		reverse_rotate_stack('a', a, b);
	else if (first > second && second < third && first > third)
		rotate_stack('a', a, b);
	else if (first > second && second > third && first > third)
	{
		swap_stack('a', a, b);
		reverse_rotate_stack('a', a, b);
	}
}

void	sort_three(t_stack **a)
{
	long	first;
	long	second;
	long	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	exec_moves(a, first, second, third);
}
