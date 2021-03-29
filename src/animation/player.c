/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** player
*/

#include "player.h"
#include "window_fonction.h"

void anim_player(player_t *player)
{
    int time = (int)(time_to_float(player->animation_clock) * 10);

    if (time > 14) {
        time = 0;
        sfClock_restart(player->animation_clock);
    }
    if (player->flip == sfFalse) {
        sfSprite_setTextureRect(player->sprite, (sfIntRect)\
        {time * 64, 64 * player->anime, 64, 64});
    } else {
        sfSprite_setTextureRect(player->sprite, (sfIntRect)\
        {time * 64 + 64, 64 * player->anime, -64, 64});
    }
}