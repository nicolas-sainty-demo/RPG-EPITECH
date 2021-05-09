/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_player
*/

#include <malloc.h>
#include "projectile.h"
#include "player.h"

void free_player(player_t *player)
{
    sfClock_destroy(player->animation_clock);
    free(player->inventaire);
    free_particules(player->particl);
    free_tab_projectile(player->proj);
    sfSprite_destroy(player->sprite);
}