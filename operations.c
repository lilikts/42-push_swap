#include "push_swap.h"

void push(t_stack **dest, t_stack **src)
{
    if (!*src)
        return;
    t_stack *temp;
    temp = *src;
    *src = temp->next;
    temp->next = *dest;
    *dest = temp;
}

void swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;
    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}
void rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    last = *stack;
    while (last->next)
        last = last->next;
    first->next = NULL;
    last->next = first;
}

void reverse_rotate(t_stack **stack)
{
    t_stack *prev;
    t_stack *last;

    if (!*stack || !(*stack)->next)
        return;
    prev = *stack;
    while (prev->next && prev->next->next)
        prev = prev->next;
    last = prev->next;
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}