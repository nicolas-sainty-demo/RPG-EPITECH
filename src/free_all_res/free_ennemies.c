/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_ennemies
*/

#include <malloc.h>
#include "projectile.h"
#include "ennemies.h"

void free_ennemie(entity_enemy_t *ennemies)
{
    sfClock_destroy(ennemies->animation_clock);
    sfClock_destroy(ennemies->delay_attack);
    sfSprite_destroy(ennemies->sprite);
    if (ennemies->type == 1)
        free_projectile(ennemies->proj);
    free(ennemies);
}

void free_tab_ennemies(entity_enemy_t **ennemies)
{
    for (int i = 0; ennemies[i]; i++) {
        free_ennemie(ennemies[i]);
    }
    free(ennemies);
}