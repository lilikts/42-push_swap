#include "push_swap.h"

static void index(t_stack *stack)
{
	int i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

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

static void target_node_b(t_stack *a, t_stack *b)
{
    t_stack *current;
    long closest_smaller;
    while (a)
    {
		a->target = NULL;
		current = b;
		closest_smaller = LONG_MIN;
		while (current)
		{
			if (current->num < a->num && current->num > closest_smaller)
			{
				closest_smaller = current->num;
				a->target = current;
			}
			current = current->next;
		}
    	if (a->target == NULL)
		{
			current = b;
			closest_smaller = LONG_MAX;
			while (current)
			{
				if (current->num < closest_smaller)
				{
					closest_smaller = current->num;
					a->target = current;
				}
				current = current->next;
			}
		}
		a = a->next;
	}
}

static void target_node_a(t_stack *a, t_stack *b)
{
	t_stack *current;
    long closest_bigger;

	while (b)
	{
		b->target = NULL;
		current = a;
		closest_bigger = LONG_MAX;
		while (current)
		{
			if (current->num > b->num && current->num < closest_bigger)
			{
				closest_bigger = current->num;
				b->target = current;
			}
			current = current->next;
		}
		if (b->target == NULL)
		{
			current = a;
			closest_bigger = LONG_MIN;
			while (current)
			{
				if (current->num > closest_bigger)
				{
					closest_bigger = current->num;
					b->target = current;
				}
				current = current->next;
			}
		}
		b = b->next;
	}
}

void sort_stack(t_stack *a, t_stack *b)
{
    
    if (stack_length(a) > 3)
        push_stack('b', a, b);
    if (stack_length(a) > 3)
        push_stack('b', a, b);
    while (a > 3)
    {
        index(a);
        index(b);
        target_node_b(a, b);
        execute_cheapest_move(a, b);
    }
    sort_three(a);
	while (b >= 0)
	{
		index(a);
		index(b);
		target_node_a(a, b);
		execute_cheapest_move(b, a);
	}
}