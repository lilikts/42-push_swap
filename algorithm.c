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

void target_in_b(char)

void target_node(char dest, t_stack *x, t_stack *y)
{
    t_stack *current;
    long closest_smaller;
	long closest_bigger;

	if (dest == 'a')
	{
		while (x)
		{
			x->target = NULL;
			current = y;
			closest_smaller = LONG_MIN;
			while (current)
			{
				if (current->num < x->num && current->num > closest_smaller)
				{
					closest_smaller = current->num;
					x->target = current;
				}
				current = current->next;
			}
			if (x->target == NULL)
			{
				current = y;
				closest_smaller = LONG_MAX;
				while (current)
				{
					if (current->num < closest_smaller)
					{
						closest_smaller = current->num;
						x->target = current;
					}
					current = current->next;
				}
			}
			x = x->next;
		}
	}
    else if (dest == 'b')
	{
		while (y)
		{
			y->target = NULL;
			current = x;
			closest_bigger = LONG_MAX;
			while (current)
			{
				if (current->num > y->num && current->num < closest_bigger)
				{
					closest_bigger = current->num;
					y->target = current;
				}
				current = current->next;
			}
			if (y->target == NULL)
			{
				current = x;
				closest_bigger = LONG_MIN;
				while (current)
				{
					if (current->num > closest_bigger)
					{
						closest_bigger = current->num;
						y->target = current;
					}
					current = current->next;
				}
			}
			y = y->next;
		}
	}
}

void sort_stack(t_stack **a, t_stack **b)
{
    
    if (ft_arrlen(a) > 3)
        push_stack('b', a, b);
    if (ft_arrlen(a) > 3)
        push_stack('b', a, b);
    while (a > 3)
    {
        index(a);
        index(b);
        target_node('a', a, b);
        execute_cheapest_move(a, b);
    }
    sort_three(a);
	while (b >= 0)
	{
		index(a);
		index(b);
		target_node('b', a, b);
		execute_cheapest_move(b, a);
	}
}