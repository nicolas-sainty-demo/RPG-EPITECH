/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics/Sprite.h>

typedef struct entity_passif
{
    sfSprite *sprite;
    char anime;
} entity_passif_t;

typedef struct entity_enemy
{
    sfSprite *sprite;
    char anime;
} entity_enemy_t;

#endif /* !ENTITY_H_ */
