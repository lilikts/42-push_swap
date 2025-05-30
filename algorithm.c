#include "push_swap.h"

void sort_two(t_stack **a)
{
	long first;
	long second;

	first = (*a)->num;
	second = (*a)->next->num;

	if (first < second)
		return;
	else
		swap_stack('a', a, NULL);
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

void set_index(t_stack *stack)
{
	int index;
	index = 0;
	if (!stack)
		return;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
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
			closest_smaller = LONG_MIN;
			while (current)
			{
				if (current->num > closest_smaller)
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
			closest_bigger = LONG_MAX;
			while (current)
			{
				if (current->num < closest_bigger)
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

void sort_stack(t_stack **a, t_stack **b)
{
	if (stack_length(*a) > 3)
        push_stack('b', a, b);
    if (stack_length(*a) > 3)
        push_stack('b', a, b);
    while (stack_length(*a) > 3)
    {
        set_index(*a);
        set_index(*b);
        target_node_b(*a, *b);
        execute_cheapest_move_a(a, b);
    }
    sort_three(a);
	printf("NACH SOrT THREE:\n");
	print_stack_a(*a);
	print_stack_b(*b);
	while (*b != NULL)
	{
		set_index(*a);
		set_index(*b);
		target_node_a(*a, *b); //richtig
		execute_cheapest_move_b(a, b); 
		// print_stack_a(*a);
		// print_stack_b(*b);
	}
	final_rotation(a, b);
	print_stack_a(*a);
}
