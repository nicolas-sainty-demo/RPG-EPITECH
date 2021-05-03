/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_ennemies
*/

#include "window_struc.h"
#include <malloc.h>

int get_tab_len(entity_enemy_t *const *ennemies)
{
    int i = 0;

    while (ennemies && ennemies[i])
        i++;
    return (i);
}

int realloc_my_tab_ennemies(entity_enemy_t ***ennemies, int const j)
{
    int size = get_tab_len(*ennemies);
    int z = 0;
    entity_enemy_t **new_tab = malloc(size * sizeof(entity_enemy_t *));

    if (!new_tab)
        return (84);
    for (int i = 0; (*ennemies)[i]; i++) {
        if (i != j) {
            new_tab[z] = (*ennemies)[i];
            z++;
        }
    }
    new_tab[z] = NULL;
    *ennemies = new_tab;
    return (0);
}

void update_ennemies(the_window *windows)
{
    for (int i = 0; windows->scene->enemy && windows->scene->enemy[i]; i++) {
        if (windows->scene->enemy[i]->hp <= 0) {
            realloc_my_tab_ennemies(&windows->scene->enemy, i);
            break;
        }
    }
}