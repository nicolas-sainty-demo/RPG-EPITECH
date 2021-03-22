/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** my_strlen
*/

#include <stdlib.h>

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strlen_to_c(const char *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c) {
        i++;
    }
    return (i);
}

int nbr_of_c(const char *str, char c)
{
    int nbr_of_c = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i] == c)
            nbr_of_c += 1;
    return (nbr_of_c);
}

int my_int_len(int *i)
{
    int j = 0;

    while (i[j] != '\0')
        j += 1;
    return (j);
}