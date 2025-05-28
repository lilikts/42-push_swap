#include "push_swap.h"

static void calculate_cost(t_stack *a, t_stack *b)
{
    int a_len = stack_length(a);
    int b_len = stack_length(b);
	t_stack *current;
	current = a;
    while (current)
    {
        if (current->index <= a_len / 2)
		{
            current->a_cost = current->index;
		}
        else
			current->a_cost = current->index  - a_len;

        if (current->target && current->target->index <= b_len / 2)
            current->b_cost = current->target->index;
        else
		{
            current->b_cost = current->target->index - b_len;
		}
			
        current->total_cost = abs(current->a_cost) + abs(current->b_cost);
        current = current->next;
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
    calculate_cost(*a, *b);
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
	if (dest == 'a')
		push_stack('a', a, b);
    else if (dest == 'b')
		push_stack('b', a, b);
}