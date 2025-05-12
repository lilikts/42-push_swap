#include "push_swap.h"

int no_duplicates(char **argv)
{

}

int check_overflow(char *str)
{

}

static t_stack *transform_to_int(char **args)
{
    t_stack *a;
    int size;
    int i;
    int temp;

    size = ft_arrlen(args);
    i = 0;
    while (i < size)
    {
        temp = ft_atolo(args[i]);
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
    args = NULL;
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
    int i;

    i = 0;
    if (argc < 2 || argv[1][0] == '\0')
        return (NULL);
    if (valid_arguments(argc, argv))
        return (NULL);
    a = transform_input(argc, argv);
    if (no_duplicates(a))
        return (NULL);
    while(a)
    {
        if (check_overflow(a))
            return (NULL);
        i++;
    }
    return (a);
}