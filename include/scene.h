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

typedef struct scene
{
    entity_enemy_t **enemy;
    entity_passive_t **passive;
    map_t *map;
    player_t *player;
    sfVector2f **pos_items;
} scene_t;

#endif /* !SCENE_H_ */
