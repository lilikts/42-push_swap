#include "push_swap.h"

void	sort_two(t_stack **a)
{
	long	first;
	long	second;

	first = (*a)->num;
	second = (*a)->next->num;
	if (first < second)
		return ;
	else
		swap_stack('a', a, NULL);
}

void	sort_three(t_stack **a)
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

void	set_index(t_stack *stack)
{
	int	index;

	index = 0;
	if (!stack)
		return ;
	while (stack)
	{
		stack->index = index;
		stack = stack->next;
		index++;
	}
}

void	sort_stack(t_stack **a, t_stack **b)
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
	while (*b != NULL)
	{
		set_index(*a);
		set_index(*b);
		target_node_a(*a, *b);
		execute_cheapest_move_b(a, b);
	}
	final_rotation(a, b);
}
