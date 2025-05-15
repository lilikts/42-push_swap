#include "push_swap.h"

void push_stack(char dest, t_stack **a, t_stack **b)
{
    if (dest == 'a')
    {
        push(a, b);
        ft_printf("pa\n");
    }
    else if (dest == 'b')
    {
        push(b, a);
        ft_printf("pb\n");
    }
}

void swap_stack(char dest, t_stack **a, t_stack **b)
{
    if (dest == 'a')
    {
        swap(a);
        ft_printf("sa\n");
    }
    else if (dest == 'b')
    {
        swap(b);
        ft_printf("sb\n");
    }
    else if (dest == 's')
    {
        swap(a);
        swap(b);
        ft_printf("ss\n");
    }
}
void rotate_stack(char dest, t_stack **a, t_stack **b)
{
    if (dest == 'a')
    {
        rotate(a);
        ft_printf("ra\n");
    }
    else if (dest == 'b')
    {
        rotate(b);
        ft_printf("rb\n");
    }
    else if (dest == 'r')
    {
        rotate(a);
        rotate(b);
        ft_printf("rr\n");
    }

}
void reverse_rotate_stack(char dest, t_stack **a, t_stack **b)
{
    if (dest == 'a')
    {
        reverse_rotate(a);
        ft_printf("rra\n");
    }
    else if (dest == 'b')
    {
        reverse_rotate(b);
        ft_printf("rrb\n");
    }
    else if (dest == 'r')
    {
        reverse_rotate(a);
        reverse_rotate(b);
        ft_printf("rrr\n");
    }
}