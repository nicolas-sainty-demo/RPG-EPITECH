/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** is_env
*/

#include "str.h"

void is_occurence(char *const haystack, char *const needle, int *i, int *j)
{
    while (haystack[*i] && needle[*j]) {
        if (haystack[*i] == needle[*j])
            (*j)++;
        (*i)++;
    }
}

static int my_strstr(char *const haystack, char *const needle)
{
    int i = 0;
    int j = 0;

    if (!haystack || !needle)
        return (0);
    is_occurence(haystack, needle, &i, &j);
    if (j == my_strlen(needle))
        return (1);
    return (0);
}

int check_if_is_display(char **env)
{
    int is_display = 0;

    for (int i = 0; env[i]; i++) {
        if (my_strstr(env[i], "DISPLAY"))
            is_display++;
    }
    return (is_display);
}

int is_env(char **env)
{
    int is_display = 0;

    if (env == NULL)
        return (84);
    is_display = check_if_is_display(env);
    if (is_display)
        return (0);
    return (84);
}