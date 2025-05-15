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
        error_message();
    print_stack(b);
    push(&b,&a);
    print_stack(b);
    return (0);
}