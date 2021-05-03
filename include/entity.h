/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>

typedef struct entity_passive
{
    sfSprite *sprite;
    char anime;
    sfClock *animation_clock;
    sfBool flip;
    int type;
    int hp;
    int speed;
    int damage;
} entity_passive_t;

typedef struct entity_enemy
{
    sfSprite *sprite;
    char anime;
    int type;
    int hp;
    int hp_max;
    int speed;
    int damage;
    sfClock *animation_clock;
    sfBool flip;
} entity_enemy_t;

void anim_enemy(entity_enemy_t *enemy);
void anim_passive(entity_passive_t *passive);

#endif /* !ENTITY_H_ */
