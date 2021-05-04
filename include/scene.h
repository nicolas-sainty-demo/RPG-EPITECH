/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** scene
*/

#ifndef SCENE_H_
#define SCENE_H_

#include "entity.h"
#include "player.h"
#include "map.h"

typedef struct items_s
{
    sfVector2f pos;
    char type;
    struct items_s *next;
} items_t;

typedef struct scene
{
    entity_enemy_t **enemy;
    entity_passive_t **passive;
    map_t *map;
    player_t *player;
    items_t *pos_items;
} scene_t;

#endif /* !SCENE_H_ */
