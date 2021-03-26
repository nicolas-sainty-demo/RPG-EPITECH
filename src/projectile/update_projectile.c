/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_projectile
*/

#include "errors_define.h"

#include "projectile.h"

void check_state_projectile(projectile_t *projectile)
{
    sfFloatRect bounds_spt =\
     sfSprite_getGlobalBounds(projectile->spt_projectile);

    if (projectile->state == shooted) {
        move_projectile(projectile, bounds_spt);
        is_projectile_arrived(projectile, bounds_spt);
    }
    reload_ammo(projectile);
}

void update_projectile(projectile_t *projectile)
{
    if (!projectile || !projectile->spt_projectile)
        display_error(ERROR_NO_MALLOC_);
    else
        check_state_projectile(projectile);
}