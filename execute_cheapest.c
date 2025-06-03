/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cheapest.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:04:45 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/03 13:39:14 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_combi_rot(t_stack **a, t_stack **b, int *am, int *bm)
{
	while (*am > 0 && *bm > 0)
	{
		rotate_stack('r', a, b);
		(*am)--;
		(*bm)--;
	}
	while (*am < 0 && *bm < 0)
	{
		reverse_rotate_stack('r', a, b);
		(*am)++;
		(*bm)++;
	}
}

static void	exec_individ_rot(t_stack **a, t_stack **b, int am, int bm)
{
	while (am > 0)
	{
		rotate_stack('a', a, b);
		am--;
	}
	while (am < 0)
	{
		reverse_rotate_stack('a', a, b);
		am++;
	}
	while (bm > 0)
	{
		rotate_stack('b', a, b);
		bm--;
	}
	while (bm < 0)
	{
		reverse_rotate_stack('b', a, b);
		bm++;
	}
}

void	execute_cheapest_move_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		a_moves;
	int		b_moves;

	calculate_cost_a(*a, *b);
	cheapest = calculate_cheapest(*a);
	if (!cheapest)
		return ;
	a_moves = cheapest->a_cost;
	b_moves = cheapest->b_cost;
	exec_combi_rot(a, b, &a_moves, &b_moves);
	exec_individ_rot(a, b, a_moves, b_moves);
	push_stack('b', a, b);
}

void	execute_cheapest_move_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	int		a_moves;
	int		b_moves;

	calculate_cost_b(*a, *b);
	cheapest = calculate_cheapest(*b);
	if (!cheapest)
		return ;
	a_moves = cheapest->a_cost;
	b_moves = cheapest->b_cost;
	exec_combi_rot(a, b, &a_moves, &b_moves);
	exec_individ_rot(a, b, a_moves, b_moves);
	push_stack('a', a, b);
}
