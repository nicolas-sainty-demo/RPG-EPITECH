/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** my_tablen
*/

#include <stdlib.h>

int get_tab_max(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i += 1;
    return (i);
}