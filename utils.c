#include "push_swap.h"

t_stack *new_stack(int temp)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    // if (!new)
    //     error_msg();
    new->num = temp;
    new->next = NULL;
    return (new);
}

int ft_arrlen(char **arr)
{
    int i;

    i = 0;
    while (arr && arr[i])
        i++;
    return (i);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
		(stack_last(*stack))->next = new;
}

void error_message(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}