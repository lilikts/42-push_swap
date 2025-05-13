#include "push_swap.h"

int no_duplicates(t_stack *a)
{
    t_stack *temp;

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

static t_stack *transform_to_int(char **args)
{
    t_stack *a;
    int size;
    int i;
    long temp;

    a = NULL;
    size = ft_arrlen(args);
    i = 0;
    while (i < size)
    {
        temp = ft_atolo(args[i]);
        if (temp > INT_MAX || temp < INT_MIN)
            return (NULL);
        stack_add_back(&a, new_stack(temp));
        i++;
    }
    //free
    return (a);
}

static t_stack *transform_input(int argc, char **argv)
{
    t_stack *a;
    char **args;
    int i;
    int j;

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
    return (a);
}

t_stack *handle_input(int argc, char **argv)
{
    t_stack *a;

   
    if (argc < 2 || argv[1][0] == '\0')
        return (NULL);
    if (valid_arguments(argc, argv))
        return (NULL);
    a = transform_input(argc, argv);
    if (no_duplicates(a))
        return (NULL);
    return (a);
}
