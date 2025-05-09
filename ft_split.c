#include <stdio.h>
#include <stdlib.h>

int num_of_words(char const *s, char c)
{
    int i;
    int count;
    count = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if ((s[i] != c) && (i == 0 || s[i - 1] == c))
            count++;
        i++;
    }
    return (count);
}

char *copy_word(char const *s, char c, int start)
{
    char *dup;
    int end;
    end = start;
    int i;
    i = 0;
    while (s[end] != '\0' || s[end] != c)
        end++;
    dup = (char *)malloc(sizeof(char) * (end - start) + 1);
    // if (!dup)
    //     free_mem(dup);
    while (start < end)
    {
        dup[i] = s[start];
        i++;
        start++;
    }
    dup[i] = '\0';
    return (dup);
}

// char **ft_split(char const *s, char c)
// {
//     int word_count;
//     char **array;
//     int i;
//     int length;

//     i = 0;
//     word_count = num_of_words(s, c);
//     array = (char **)malloc(sizeof(char *) * (word_count + 1));
//     if (!array)
//         free_mem(array);
//     while (i < word_count)
//     {
//         length = 0;
//         while (*s != '\0' && *s == c)
//             s++;
//         while (s[length] != '\0' && s[length] != c)
//             length++;
//         array[i] = copy_word((char *)s, length);
//         if (!array)
//             free_mem(array);
//         s = s + length;
//         i++;
//     }
//     array[i] = '\0';
//     return (array);
// }

int main (void)
{
    char const *s = "Hello-----my-name-is-Lilli";
    char c = '-';
    int words = num_of_words(s, c);
    printf("%i\n", words);
    char *dup = copy_word(s, c, 7);
    int i = 0;
    printf("%s\n", dup);
    return (0);
}

