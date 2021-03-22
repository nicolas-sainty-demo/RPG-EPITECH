/*
** EPITECH PROJECT, 2021
** sdfgdsfsdg
** File description:
** str_to_word_arry
*/

#include <stdlib.h>

#include "str.h"

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

void fill_arry(index_t *i, int ***tab, char *str)
{
    while (i->x <= i->m) {
        (*tab)[i->y][i->x] = str[i->z];
        i->z += 1;
        i->x += 1;
    }
}

static void cpy_arry(char *str, int ***tab)
{
    index_t i = { 0 };

    while (str != NULL && str[i.z] != '\0') {
        i.m = str_len_for_c(str, '\n', i.z);
        (*tab)[i.y] = malloc(sizeof(int) * (i.m + 3));
        if ((*tab)[i.y] == NULL) {
            (*tab) = NULL;
            return;
        }
        fill_arry(&i, tab, str);
        (*tab)[i.y][i.x] = '\0';
        i.x = 0;
        i.y += 1;
        if (str[i.z] != '\0')
            i.z += 1;
    }
    (*tab)[i.y] = NULL;
}

int **str_to_int_arry(char *str)
{
    int **tab = malloc(sizeof(int *) * (char_nbr_in(str, '\n') + 2));

    if (tab == NULL || str == NULL)
        return (NULL);
    cpy_arry(str, &tab);
    return (tab);
}