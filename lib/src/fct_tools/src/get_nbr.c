/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** get_nbr
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str);

void my_putchar(char c);

int my_put_nbr(int nb);

char *my_revstr(char *str)
{
    int i = 0;
    int j;
    char rts;

    j = my_strlen(str) - 1;
    while (i < j)
    {
        rts = str[i];
        str[i] = str[j];
        str[j] = rts;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}

int nbr_is(char c)
{
    int i = 0;
    char base[] = \
    "0123456789abcdefghijklmopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVWXYZ";

    while (base[i] != c)
        i++;
    return (i);
}

int my_get_nbr(char *char_nbr, int base)
{
    int the_nbr = 0;
    int negatif = 1;
    int the_len = 0;

    if (char_nbr[0] == '-')
        negatif = -1;
    the_len = my_strlen(char_nbr) - 1;
    for (int i = 0; i <= the_len; i++) {
        the_nbr *= base;
        the_nbr += (nbr_is(char_nbr[i]) % base);
    }
    return (the_nbr * negatif);
}