/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkloters <lkloters@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:04:29 by lkloters          #+#    #+#             */
/*   Updated: 2025/06/06 12:13:43 by lkloters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	no_duplicates(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		while (temp)
		{
			if (a->num == temp->num)
				return (1);
			temp = temp->next;
		}
		a = a->next;
	}
	return (0);
}

static int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

static t_stack	*transform_to_int(char **args)
{
	t_stack	*a;
	int		size;
	int		i;
	long	temp;

	a = NULL;
	size = ft_arrlen(args);
	i = 0;
	while (i < size)
	{
		temp = ft_atolo(args[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			free_stack(a);
			return (NULL);
		}
		stack_add_back(&a, new_stack(temp));
		i++;
	}
	return (a);
}

static t_stack	*transform_input(int argc, char **argv)
{
	t_stack	*a;
	char	**args;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = (char **)malloc(sizeof(char *) * argc);
		if (!args)
			return (NULL);
		while (i < argc)
			args[j++] = argv[i++];
		args[j] = NULL;
	}
	a = transform_to_int(args);
	if (argc == 2)
		free_split(args);
	else
		free(args);
	return (a);
}

t_stack	*handle_input(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2 || argv[1] == NULL || argv[1][0] == '\0')
		return (NULL);
	if (valid_arguments(argc, argv))
		return (NULL);
	a = transform_input(argc, argv);
	if (!a)
		return (NULL);
	if (no_duplicates(a))
	{
		free_stack(a);
		error_message();
	}
	else if (is_sorted(a))
	{
		free_stack(a);
		exit(EXIT_SUCCESS);
	}
	return (a);
}
