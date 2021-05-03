/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

#include "projectile_struct.h"

typedef enum animation
{
    player_stay = 0,
    player_run_bot = 1,
    player_run = 2,
    player_run_top = 3
} animation_t;

typedef struct player
{
    char *inventaire;
    sfSprite *sprite;
    char anime;
    int hp;
    sfClock *animation_clock;
    sfBool flip;
    int speed;
    projectile_t **proj;
} player_t;

void anim_player(player_t *player);

#endif /* !PLAYER_H_ */
