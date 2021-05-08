/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_char_after_c
*/

#include "str.h"
#include <stdlib.h>

static int str_len_after_i(const char *str, int i)
{
    int len = 0;

    if (str == NULL || my_strlen(str) < i)
        return (0);
    while (str[i++] != '\0')
        len += 1;
    return (len);
}

static int check_is_errors(const char *str, const char c)
{
    int i = 0;

    if (str == NULL)
        return (-1);
    while (str[i] != '\0' && str[i] != c)
        i += 1;
    if (str[i] == '\0')
        return (-1);
    return (i);
}

char *get_string_after_c(const char *str, const char c)
{
    char *dest = NULL;
    int i = 0;
    int j = 0;

    i = check_is_errors(str, c);
    if (i == -1)
        return (NULL);
    dest = malloc(sizeof(char) * (str_len_after_i(str, i++)));
    if (dest == NULL)
        return (NULL);
    while (str[i] != '\0')
        dest[j++] = str[i++];
    dest[j] = str[i];
    return (dest);
}