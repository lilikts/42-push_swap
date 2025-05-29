#include "push_swap.h"

static void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%ld\n", stack->num);
        stack = stack->next;
    }
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = handle_input(argc, argv);
    b = NULL;
    if (!a)
    {
        free_stack(a);
        error_message();
    }
	print_stack(a);
	if (stack_length(a) == 2)
		sort_two(&a);
    else if (stack_length(a) == 3)
        sort_three(&a);
    else
        sort_stack(&a, &b);
	print_stack(a);
    free_stack(a);
    free_stack(b);
    return (0);
}
