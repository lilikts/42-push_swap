#include "push_swap.h"

void sort_three(t_stack **a)
{
    long first; 
    long second;
    long third;
    t_stack **b;
    b = NULL;

    first = (*a)->num;
    second = (*a)->next->num;
    third = (*a)->next->next->num;
    if (first < second && second < third)
        return;
    else if (first > second && second < third && first < third)
        swap_stack('a', a, b);
    else if (first > second && second > third)
    {
        swap_stack('a', a, b);
        reverse_rotate_stack('a', a, b);
    }
    else if (first > second && second > third)
        rotate_stack('a', a, b);
    else if (first < second && second > third && first < third)
    {
        swap_stack('a', a, b);
        rotate_stack('a', a, b);
    }
    else if (first < second && second > third && first > third)
        reverse_rotate_stack('a', a, b);
}

void index(t_stack *stack)
{
	int i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void target_node(t_stack *a, t_stack *b)
{
    t_stack *current_b;
    long closest_smaller;

    while (a)
    {
        a->target = NULL;
        current_b = b;
        closest_smaller = LONG_MIN;
        while (current_b)
        {
            if (current_b->num < a->num && current_b->num > closest_smaller)
            {
                closest_smaller = current_b->num;
                a->target = current_b;
            }
            current_b = current_b->next;
        }
        if (a->target == NULL)
        {
            current_b = b;
            closest_smaller = LONG_MAX;
            while (current_b)
            {
                if (current_b->num < closest_smaller)
                {
                    closest_smaller = current_b->num;
                    a->target = current_b;
                }
            }
            current_b = current_b->next;
        }
        a = a->next;
    }
}

void sort_stack(t_stack **a, t_stack **b)
{
    
    if (stack_length > 3)
        push_stack('b', a, b);
    if (stack_length > 3)
        push_stack('b', a, b);
    while (a > 3)
    {
        index(a);
        index(b);
        target_node(a, b);
        execute_cheapest_move(a, b);
    }
    sort_three(a);
}