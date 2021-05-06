/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_projectile
*/

#include <stdlib.h>

#include <SFML/Graphics/Texture.h>

#include "errors_define.h"

#include "projectile.h"

#define RELOAD_MUN_ 5

projectile_t *init_projectile(char *path_projectile, int radius, int speed\
, int reload_time)
{
    projectile_t *basic_projectile = malloc(sizeof(projectile_t));

    if (!basic_projectile)
        return (NULL);
    basic_projectile->particl = init_particl(300, 1000 * reload_time, sfRed);
    basic_projectile->clock = sfClock_create();
    basic_projectile->spt_projectile = sfSprite_create();
    basic_projectile->text_projectile = \
    sfTexture_createFromFile(path_projectile, NULL);
    if (!basic_projectile->spt_projectile || \
    !basic_projectile->text_projectile || !basic_projectile->clock)
        return (NULL);
    sfSprite_setTexture(basic_projectile->spt_projectile, \
    basic_projectile->text_projectile, sfTrue);
    basic_projectile->state = no_shoot;
    basic_projectile->speed_given = speed;
    basic_projectile->radius = radius;
    basic_projectile->reload_time = reload_time;
    sfSprite_setPosition(basic_projectile->spt_projectile, POS_INITIAL_PROJ);
    return (basic_projectile);
}

projectile_t **init_tab_projectile(char *const path_projectile\
, const int radius, const int speed, const int nb_of_projectiles)
{
    int i = 0;
    projectile_t **tab_projectile = malloc(sizeof(projectile_t) * \
    (nb_of_projectiles+1));

    if (!tab_projectile) {
        display_error(ERROR_NO_MALLOC_);
        return (NULL);
    }
    for ( ; i < nb_of_projectiles; i++) {
        tab_projectile[i] = init_projectile(path_projectile, radius, speed\
        , RELOAD_MUN_);
        if (!tab_projectile[i]) {
            display_error(ERROR_NO_MALLOC_);
            return (NULL);
        }
    }
    tab_projectile[i] = NULL;
    return (tab_projectile);
}
