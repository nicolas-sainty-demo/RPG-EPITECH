/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** tab_of_int
*/

#include "gameplay/inventory.h"
#include <malloc.h>

int **malloc_my_tab(const int rows, const int cols)
{
    int **tab = malloc(sizeof(int *) * (rows+1));
    int i = 0;

    if (!tab || rows < 0 || cols < 0)
        return (NULL);
    while (i != rows) {
        tab[i] = malloc(sizeof(int) * (cols+1));
        if (!tab[i])
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

void memset_tab(int **tab, const int cols, const char c)
{
    int j = 0;
    int i = 0;

    while (tab[i] != NULL) {
        for ( ; j != cols; j++)
            tab[i][j] = c;
        tab[i][j] = '\0';
        j = 0;
        i++;
    }
}

void free_tab(const int rows, int **tab)
{
    for (int i = 0; i < rows; i++) {
        free(tab[i]);
    }
    free(tab);
}