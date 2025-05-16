#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_stack *temp;
    while (stack)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}

void free_split(char **arr)
{
    int i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

void error_message(void)
{
    ft_printf("Error\n");
    exit(EXIT_FAILURE);
}
