#include "push_swap.h"

void put_in_stack(t_node *a, char **argv)
{
    int i;
    i = 0;
    while (argv[i] != NULL)
    {
        if (check_argument != 0)
        {
            write(1, "Error\n", 6);
            return (1);
        }
        else
        a
    }
    // while noch arguments
    // check ob argument richtige vorraussetzung
    // wandel argv string in int um
    // speicher in a

}
int main (int argc, char **argv)
{
    t_node *a;
    t_node *b;

    a = NULL;
    b = NULL;
    if (argc >= 2 && argv[1][0] != NULL)
    {
        if (argc == 2)
            argv = ft_split(argv[1], " ");
        put_in_stack(&a, argv + 1);
        // sorting algorithm
    }
    else
    {
        write(1, "Error\n", 6);
        return (1);
    }
    return (0);
}