/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_entity
*/

#include <malloc.h>
#include "entity.h"

void free_entity_passive(entity_passive_t *entity)
{
    sfClock_destroy(entity->animation_clock);
    sfSprite_destroy(entity->sprite);
    free(entity);
}

void free_tab_entity_passive(entity_passive_t **entity)
{
    for (int i = 0; entity[i]; i++) {
        free_entity_passive(entity[i]);
    }
    free(entity);
}