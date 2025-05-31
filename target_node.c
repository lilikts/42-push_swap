#include "push_swap.h"

void target_node_b(t_stack *a, t_stack *b)
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

void target_node_a(t_stack *a, t_stack *b)
{
	t_stack	*current;
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