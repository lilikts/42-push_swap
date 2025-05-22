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
 

void target_node(t_stack *a, t_stack *b)
{
    t_stack *current_b;
    long closest_smaller;

    while (a)
    {
        a->target = NULL;
        current_b = b;
        closest_smaller = LONG_MIN;
        while (current_b)
        {
            if (current_b->num < a->num && current_b->num > closest_smaller)
            {
                closest_smaller = current_b->num;
                a->target = current_b;
            }
            current_b = current_b->next;
        }
        if (a->target == NULL)
        {
            current_b = b;
            closest_smaller = LONG_MAX;
            while (current_b)
            {
                if (current_b->num < closest_smaller)
                {
                    closest_smaller = current_b->num;
                    a->target = current_b;
                }
            }
            current_b = current_b->next;
        }
        a = a->next;
    }
}

void calculate_cost(t_stack *a, t_stack *b)
{
    int a_cost;
    int b_cost;
    
    while (a)
    {
        if (a->index <= ft_arrlen(a) / 2)
            a_cost = a->index;
        else
            a_cost = a->index - ft_arrlen(a);
        if (a->target && a->target->index <= ft_arrlen(b) / 2)
            b_cost = a->target->index;
        else if (a->target)
            b_cost = a->target->index - ft_arrlen(b);
        else
            b_cost = 0;
        a->cost = a_cost + b_cost;
        a = a->next;
    }
}

void sort_stack(t_stack **a, t_stack **b)
{
    
    if (stack_length > 3)
        push_stack('b', a, b);
    if (stack_length > 3)
        push_stack('b', a, b);
    while (a)
    {
        index(a);
        index(b);
        target_node(a, b);
        calculate_cost(a, b);
    }
   
}