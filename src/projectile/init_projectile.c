/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_projectile
*/

#include <SFML/Graphics/Texture.h>

#include "projectile.h"

projectile_t init_projectile(char *path_projectile, int radius, int speed)
{
    projectile_t basic_projectile = { 0 };

    basic_projectile.clock = sfClock_create();
    basic_projectile.spt_projectile = sfSprite_create();
    basic_projectile.text_projectile = \
    sfTexture_createFromFile(path_projectile, NULL);
    if (!basic_projectile.spt_projectile || !basic_projectile.text_projectile\
     || !basic_projectile.clock)
        return ((projectile_t){0});
    sfSprite_setTexture(basic_projectile.spt_projectile, \
    basic_projectile.text_projectile, sfTrue);
    basic_projectile.state = no_shoot;
    basic_projectile.speed_given = speed;
    basic_projectile.radius = radius;
    return (basic_projectile);
}