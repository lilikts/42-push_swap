#include "push_swap.h"

void final_rotation(t_stack **a, t_stack **b)
{
	t_stack *min;
	t_stack *current;
	if (!a || !*a)
		return;
	set_index(*a);
	min = *a;
	current = *a;
	while (current)
	{
		if (current->num < min->num)
			min = current;
		current = current->next;
	}
	if (min->index <= stack_length(*a) / 2)
	{
		while(min->index > 0)
		{
			rotate_stack('a', a, b);
			min->index--;
		}
	}
	else
	{
		min->index = min->index - stack_length(*a);
		while (min->index < 0)
		{
			reverse_rotate_stack('a', a, b);
			min->index++;
		}
	}
}
