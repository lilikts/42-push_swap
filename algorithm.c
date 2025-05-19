#include "push_swap.h"

unsigned int stack_length(t_stack *a)
{
    unsigned int length;
    length = 0;
    while (a)
    {
        a = a->next;
        length++;
    }
    return (length);
}

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

void