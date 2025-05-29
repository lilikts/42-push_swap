#include "push_swap.h"

// static void print_stack(t_stack *stack)
// {
//     if (!stack)
//     {
//         printf("Stack: (empty)\n");
//         return;
//     }

//     while (stack)
//     {
//         printf("Stack: %ld\n", stack->num);
//         stack = stack->next;
//     }
// }
// static void print_stack2(t_stack *stack)
// {
//     while (stack)
//     {
//         printf("Stack A: %ld\n", stack->num);
//         stack = stack->next;
//     }
// }

// static void print_target(t_stack *stack)
// {
//     while (stack)
//     {
//         if (stack->target)
//             printf("Node %ld -> Target %ld\n", stack->num, stack->target->num);
//         else
//             printf("Node %ld -> Target NULL\n", stack->num);
//         stack = stack->next;
//     }
// }

void set_index(t_stack *stack)
{
	int i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}
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
        execute_cheapest_move('b', a, b);
    }
    sort_three(a);
	while (*b != NULL)
	{
		set_index(*a);
		set_index(*b);
		target_node_a(*a, *b);
		execute_cheapest_move('a', a, b);
	}
	final_rotation(a, b);
}
