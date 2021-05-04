/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_ennemies
*/

#include "window_struc.h"
#include <malloc.h>
#include <stdlib.h>

int drop_the_item(items_t **pos_items, sfSprite *sprite);

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
    entity_enemy_t **new_tab = malloc(sizeof(entity_enemy_t *) * size);

    if (!new_tab)
        return (84);
    for (int i = 0; (*ennemies)[i]; i++) {
        if (i != j) {
            new_tab[z] = (*ennemies)[i];
            z++;
        }
    }
    new_tab[z] = NULL;
    free(*ennemies);
    *ennemies = new_tab;
    return (0);
}

void update_ennemies(the_window *windows)
{
    for (int i = 0; windows->scene->enemy && windows->scene->enemy[i]; i++) {
        if (windows->scene->enemy[i]->hp <= 0) {
            drop_the_item\
            (&windows->scene->pos_items, windows->scene->enemy[i]->sprite);
            realloc_my_tab_ennemies(&windows->scene->enemy, i);
            break;
        }
    }
}