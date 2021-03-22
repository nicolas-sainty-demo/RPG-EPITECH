/*
** EPITECH PROJECT, 2021
** sdfgdsfsdg
** File description:
** str_to_word_arry
*/

#include <stdlib.h>

static int char_nbr_in(char *str, char c)
{
    int i = 0;

    for (int j = 0; str[j] != '\0'; j += 1) {
        if (str[j] == c) {
            i += 1;
        }
    }
    return (i);
}

static int str_len_for_c(char *str, char c, int i)
{
    int len = 0;

    while (str[i] != '\0' && str[i] != c) {
        i += 1;
        len += 1;
    }
    return (len);
}

static void cpy_arry(char *str, char ***tab)
{
    int x = 0;
    int y = 0;
    int i = 0;

    while (str != NULL && str[i] != '\0') {
        (*tab)[y] = malloc(sizeof(char) * str_len_for_c(str, '\n', i) + 1);
        while (str[i] != '\0' && str[i] != '\n') {
            (*tab)[y][x] = str[i];
            i += 1;
            x += 1;
        }
        (*tab)[y][x] = '\0';
        x = 0;
        y += 1;
        if (str[i] != '\0')
            i += 1;
    }
    (*tab)[y] = NULL;
}

void clear_tab(char **tab)
{
    for (int y = 0; tab[y] != NULL; y += 1) {
        for (int x = 0; tab[y][x] != '\0'; x += 1) {
            if (tab[y][x] == 'X' || tab[y][x] == 'Z')
                tab[y][x] = ' ';
            if (tab[y][x] == 'P')
                tab[y][x] = ' ';
        }
    }
}

char **str_to_word_arry(char *str)
{
    char **tab = malloc(sizeof(char *) * (char_nbr_in(str, '\n') + 2));

    if (tab == NULL || str == NULL)
        return (NULL);
    cpy_arry(str, &tab);
    return (tab);
}