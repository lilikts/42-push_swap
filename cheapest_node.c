#include "push_swap.h"

static void calculate_cost(t_stack *a, t_stack *b)
{
    while (a)
    {
        if (a->index <= ft_arrlen(a) / 2)
            a->a_cost = a->index;
        else
            a->a_cost = a->index - ft_arrlen(a);
        if (a->target && a->target->index <= ft_arrlen(b) / 2)
            a->b_cost = a->target->index;
        else if (a->target)
            a->b_cost = a->target->index - ft_arrlen(b);
        else
            a->b_cost = 0;
        a->total_cost = abs(a->a_cost) + abs(a->b_cost);
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

void execute_cheapest_move(t_stack **a, t_stack **b)
{
    t_stack *cheapest;
    int a_moves;
    int b_moves;
    calculate_cost(*a, *b);
    cheapest = calculate_cheapest(a);
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