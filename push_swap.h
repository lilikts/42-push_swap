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
    struct s_stack *target;
    int total_cost;
    int a_cost;
    int b_cost;
    int index;
} typedef t_stack;

// input
int valid_arguments(int argc, char **argv);
t_stack *new_stack(int temp);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack *handle_input(int argc, char **argv);

// error_handling
void free_stack(t_stack *stack);
void free_split(char **arr);
void error_message(void);

// operations
void push(t_stack **dest, t_stack **src);
void swap(t_stack **stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);

// stack handling
void push_stack(char dest, t_stack **a, t_stack **b);
void swap_stack(char dest, t_stack **a, t_stack **b);
void rotate_stack(char dest, t_stack **a, t_stack **b);
void reverse_rotate_stack(char dest, t_stack **a, t_stack **b);

// cheapest node
void execute_cheapest_move_a(t_stack **a, t_stack **b);
void execute_cheapest_move_b(t_stack **a, t_stack **b);
// void execute_cheapest_move(char dest, t_stack **a, t_stack **b);
// utils
int stack_length(t_stack *stack);
long	ft_atolo(const char *str);
int ft_arrlen(char **arr);

// sorting algorithm
void set_index(t_stack *stack);
void sort_two(t_stack **a);
void sort_three(t_stack **a);
void sort_stack(t_stack **a, t_stack **b);
void final_rotation(t_stack **a, t_stack **b);
//testing
// void print_target(t_stack *stack);
// void print_cost(t_stack *stack);
// void print_stack_a(t_stack *stack);
// void print_stack_b(t_stack *stack);

#endif