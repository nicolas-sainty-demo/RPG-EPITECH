/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** player_projectile
*/

#include "projectile.h"
#include "player.h"

void init_elem_player(player_t *player)
{
    player->proj =\
     init_tab_projectile(PATH_PROJ, RADIUS_PROJ, SPEED_PROJ, NB_PROJ);
}