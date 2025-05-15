#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct s_stack
{
    long num;
    struct s_stack *next;
} typedef t_stack;

int valid_arguments(int argc, char **argv);
t_stack *new_stack(int temp);
int ft_arrlen(char **arr);
long	ft_atolo(const char *str);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_last(t_stack *stack);
char	**ft_split(char const *s, char c);
t_stack *handle_input(int argc, char **argv);
void error_message(void);
void push(t_stack **dest, t_stack **src);
void swap(t_stack **stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);
void push_stack(char dest, t_stack **a, t_stack **b);
void swap_stack(char dest, t_stack **a, t_stack **b);
void rotate_stack(char dest, t_stack **a, t_stack **b);
void reverse_rotate_stack(char dest, t_stack **a, t_stack **b);

#endif