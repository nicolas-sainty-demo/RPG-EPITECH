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

int realloc_vector(sfVector2f ***tab_pos, sfVector2f *new_pos)
{
    int i = 0;
    sfVector2f **new_tab = NULL;

    while ((*tab_pos) && (*tab_pos)[i])
        i++;
    new_tab = malloc(sizeof(*new_tab) * (i + 2));
    if (!new_tab)
        return (84);
    for (int j = 0; (*tab_pos) && (*tab_pos)[j]; j++)
        new_tab[j] = (*tab_pos)[j];
    new_tab[i] = new_pos;
    new_tab[i+1] = NULL;
    if (!(*tab_pos))
        free(*tab_pos);
    *tab_pos = new_tab;
    return (0);
}

int drop_the_item(sfVector2f ***pos_items, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect b = sfSprite_getGlobalBounds(sprite);

    pos.x += b.width/2;
    pos.y += b.height/2;
    if (realloc_vector(pos_items, &pos) == 84)
        return (84);
    return (0);
}

void update_ennemies(the_window *windows)
{
    for (int i = 0; windows->scene->enemy && windows->scene->enemy[i]; i++) {
        if (windows->scene->enemy[i]->hp <= 0) {
            printf("in\n");
            drop_the_item(&windows->scene->pos_items, windows->scene->enemy[i]->sprite);
            printf("\n{\nx-->%f, y-->%f\n}", windows->scene->pos_items[0]->x, windows->scene->pos_items[0]->y);
            realloc_my_tab_ennemies(&windows->scene->enemy, i);
            printf("\n{\nx-->%f, y-->%f\n}", windows->scene->pos_items[0]->x, windows->scene->pos_items[0]->y);
            exit(1) ;
        }
    }
}