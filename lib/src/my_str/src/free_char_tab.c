/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_char_tab
*/

#include <stdlib.h>

void free_char_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i += 1)
        free(tab[i]);
    free(tab);
}