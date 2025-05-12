#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

struct s_stack
{
    long num;
    struct s_stack *next;
} typedef t_stack;

int valid_arguments(int argc, char **argv);
t_stack *new_stack(int temp);
int ft_arrlen(char **arr);
int	ft_atolo(const char *str);
void	stack_add_back(t_stack **stack, t_stack *new);

#endif