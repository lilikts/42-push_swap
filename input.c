#include "push_swap.h"

int empty_argument(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

int valid_ascii(char *str)
{
    int i;
    i = 0;
    while (str[i])
    {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '+' || argv[i][j] == '-'))
            return (1);
        i++;
    }
    return (0);
}

int has_duplicates(char *str)
{
    int i;
    int letter;

    i = 0;
    while (str[i])
    {
        if ()
    }

}

int valid_sign(char *str)
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

int check_input(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        
}

int main (int argc, char **argv)
{
    int i = check_input(argc, argv);
    printf("%i\n", i);
    return (0);
}