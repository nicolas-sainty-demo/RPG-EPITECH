/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision_proj_ennemy
*/

#include <stdbool.h>
#include "window_struc.h"
#include "scene.h"
#include "projectile.h"
#include "collision.h"

void display_square_hitbox_debug(sfSprite *sprite, sfRenderWindow *windows\
, sfColor color);

bool is_collision_proj_ennemy(the_window *window)
{
    for (int i = 0; window->scene->player->proj[i]; i++) {
        for (int j = 0; window->scene->enemy[j]; j++) {
            if (window->scene->player->proj[i]->state == shooted\
             && check_if_collision_btw_circle_square\
            (RADIUS_PROJ, window->scene->player->proj[i]->spt_projectile\
            , window->scene->enemy[j]->sprite)) {
                display_square_hitbox_debug(window->scene->enemy[j]->sprite, window->window, sfRed);
                window->scene->enemy[j]->hp -=  window->scene->player->damage;
                window->scene->player->proj[i]->state = arrived;
                return (true);
            }
        }
        
    }
    return (false);
}