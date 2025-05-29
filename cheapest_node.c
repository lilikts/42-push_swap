#include "push_swap.h"

static void calculate_cost(t_stack *a, t_stack *b)
{
    int a_cost_abs;
	int b_cost_abs;
	while (a)
    {
        if (a->index <= stack_length(a) / 2)
            a->a_cost = a->index;
        else
            a->a_cost = a->index - stack_length(a);
        if (a->target && a->target->index <= stack_length(b) / 2)
            a->b_cost = a->target->index;
        else if (a->target)
            a->b_cost = a->target->index - stack_length(b);
        else
            a->b_cost = 0;
		if (a->a_cost < 0)
            a_cost_abs = -a->a_cost;
        else
            a_cost_abs = a->a_cost;

        if (a->b_cost < 0)
            b_cost_abs = -a->b_cost;
        else
            b_cost_abs = a->b_cost;

        a->total_cost = a_cost_abs + b_cost_abs;
        a = a->next;
    }
}

static t_stack *calculate_cheapest(t_stack *a)
{
    t_stack *cheapest;
    t_stack *current;

    cheapest = a;
    current = a;
    while (current)
    {
        if (current->total_cost < cheapest->total_cost)
            cheapest = current;
        current = current->next;
    }
    return (cheapest);
}

void execute_cheapest_move(char dest, t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    int a_moves;
    int b_moves;
	if (dest == 'a')
	{
		calculate_cost(*b, *a);
		cheapest = calculate_cheapest(*b);
	}
    else
	{
		calculate_cost(*a, *b);
		cheapest = calculate_cheapest(*a);
	}
	if (!cheapest)
		return ;
    a_moves = cheapest->a_cost;
    b_moves = cheapest->b_cost;
    while (a_moves > 0 && b_moves > 0)
    {
        rotate_stack('r', a, b);
        a_moves--;
        b_moves--;
    }
    while (a_moves < 0 && b_moves < 0)
    {
        reverse_rotate_stack('r', a, b);
        a_moves++;
        b_moves++;
    }
    while (a_moves > 0)
    {
        rotate_stack('a', a, b);
        a_moves--;
    }
    while (a_moves < 0)
    {
        reverse_rotate_stack('a', a, b);
        a_moves++;
    }
    while (b_moves > 0)
    {
        rotate_stack('b', a, b);
        b_moves--;
    }
    while (b_moves < 0)
    {
        reverse_rotate_stack('b', a, b);
        b_moves++;
    }
	if (dest == 'a')
		push_stack('a', a, b);
    else if (dest == 'b')
		push_stack('b', a, b);
}