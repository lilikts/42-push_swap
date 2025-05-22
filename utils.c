#include "push_swap.h"

t_stack *new_stack(int temp)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    if (!new)
    {
        free_stack(new);
        error_message();
    } 
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

long	ft_atolo(const char *str)
{
	long num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
        {
			sign = -1;
        }
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
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