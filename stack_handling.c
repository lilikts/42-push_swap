/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:03:51 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 10:03:52 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(char dest, t_stack **a, t_stack **b)
{
	if (dest == 'a')
	{
		if (!*b)
			return ;
		push(a, b);
		ft_printf("pa\n");
	}
	else if (dest == 'b')
	{
		if (!*a)
			return ;
		push(b, a);
		ft_printf("pb\n");
	}
}

void	swap_stack(char dest, t_stack **a, t_stack **b)
{
	if (dest == 'a')
	{
		if (!*a || !(*a)->next)
			return ;
		swap(a);
		ft_printf("sa\n");
	}
	else if (dest == 'b')
	{
		if (!*b || !(*b)->next)
			return ;
		swap(b);
		ft_printf("sb\n");
	}
	else if (dest == 's')
	{
		if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
			return ;
		swap(a);
		swap(b);
		ft_printf("ss\n");
	}
}

void	rotate_stack(char dest, t_stack **a, t_stack **b)
{
	if (dest == 'a')
	{
		if (!*a || !(*a)->next)
			return ;
		rotate(a);
		ft_printf("ra\n");
	}
	else if (dest == 'b')
	{
		if (!*b || !(*b)->next)
			return ;
		rotate(b);
		ft_printf("rb\n");
	}
	else if (dest == 'r')
	{
		if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
			return ;
		rotate(a);
		rotate(b);
		ft_printf("rr\n");
	}
}

void	reverse_rotate_stack(char dest, t_stack **a, t_stack **b)
{
	if (dest == 'a')
	{
		if (!*a || !(*a)->next)
			return ;
		reverse_rotate(a);
		ft_printf("rra\n");
	}
	else if (dest == 'b')
	{
		if (!*b || !(*b)->next)
			return ;
		reverse_rotate(b);
		ft_printf("rrb\n");
	}
	else if (dest == 'r')
	{
		if ((!*a || !(*a)->next) || (!*b || !(*b)->next))
			return ;
		reverse_rotate(a);
		reverse_rotate(b);
		ft_printf("rrr\n");
	}
}
