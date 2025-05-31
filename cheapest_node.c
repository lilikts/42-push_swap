#include "push_swap.h"

static void calculate_cost_a(t_stack *a, t_stack *b)
{
    // int a_cost_abs;
	// int b_cost_abs;
	int length_a;
	int length_b;
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
		// if (a->a_cost < 0)
        //     a_cost_abs = -a->a_cost;
        // else
        //     a_cost_abs = a->a_cost;

        // if (a->b_cost < 0)
        //     b_cost_abs = -a->b_cost;
        // else
        //     b_cost_abs = a->b_cost;

        // a->total_cost = a_cost_abs + b_cost_abs;
		a->total_cost = abs(a->a_cost) + abs(a->b_cost);
        a = a->next;
    }
}
static void calculate_cost_b(t_stack *a, t_stack *b)
{
    // int a_cost_abs;
	// int b_cost_abs;
	int length_a;
	int length_b;
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
            b->a_cost = 0; //?????
		// if (a->a_cost < 0)   ANPASSEN!!!!!!!!!!!!!!!!!!!!!
        //     a_cost_abs = -a->a_cost;
        // else
        //     a_cost_abs = a->a_cost;

        // if (a->b_cost < 0)
        //     b_cost_abs = -a->b_cost;
        // else
        //     b_cost_abs = a->b_cost;

        // a->total_cost = a_cost_abs + b_cost_abs;
		b->total_cost = abs(b->a_cost) + abs(b->b_cost);
        b = b->next;
    }
}

static t_stack *calculate_cheapest(t_stack *stack)
{
    t_stack *cheapest;
    t_stack *current;

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

void execute_cheapest_move_a(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    int a_moves;
    int b_moves;
    calculate_cost_a(*a, *b);
    cheapest = calculate_cheapest(*a);
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
    push_stack('b', a, b);
}

void execute_cheapest_move_b(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    int a_moves;
    int b_moves;
    calculate_cost_b(*a, *b);
    cheapest = calculate_cheapest(*b); //?
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
    push_stack('a', a, b);
}