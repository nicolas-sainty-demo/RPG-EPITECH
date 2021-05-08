/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** str_to_int
*/

#include <stdlib.h>

int my_strlen(char *const str);

int len_int(int nb)
{
    int i = 0;

    while (nb > 9) {
        i++;
        nb = nb/10;
    }
    return (i+1);
}

char *my_revstr_per(char *dest)
{
    int i = 0;
    char c = 0;
    int j = my_strlen(dest)-1;

    while (i < j) {
        c = dest[i];
        dest[i] = dest[j];
        dest[j] = c;
        i++;
        j--;
    }
    return (dest);
}

char *int_to_str(int nb)
{
    int len = len_int(nb);
    int i = 0;
    char *str = malloc(sizeof(char) * (len+1));

    if (!str)
        return (NULL);
    for ( ; i < len; i++) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
        str[i + 1] = '\0';
    }
    str[i] = '\0';
    return (my_revstr_per(str));
}