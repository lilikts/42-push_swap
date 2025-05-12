#include "push_swap.h"

static int empty_argument(char *str)
{
    int i;
    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == '\0')
        return (1);
    return (0);
}

static int valid_ascii(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '+' || str[i] == '-'))
            return (1);
        i++;
    }
    return (0);
}

static int valid_sign(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if (str[i] == '+' || str[i] == '-')
        {
            if (i > 0 && str[i - 1] != ' ')
                return (1);
            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
                return (1);
            if (str[i + 1] == '+' || str[i + 1] == '-')
                return (1);
        }
        i++;
    }
    return (0);
}

int valid_arguments(int argc, char **argv)
{
    int i;
    i = 1;
    while (i < argc)
    {
        if (empty_argument(argv[i]) == 1)
            return (1);
        if (valid_ascii(argv[i]) == 1)
            return (1);
        if (valid_sign(argv[i]) == 1)
            return (1);
        i++;
    }
    return (0);
}