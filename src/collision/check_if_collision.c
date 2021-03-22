/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** check_if_collision
*/

#include <stddef.h>

#include "collision.h"

void free_hitbox_square(sfRectangleShape *hitbox_sprite);

void free_hitbox_circle(sfCircleShape *hitbox_circle);

int check_if_collision_btw_square_without_rotation(sfSprite *const sprite_1\
, sfSprite *const sprite_2)
{
    sfRectangleShape *hitbox_sprite1 = NULL;
    sfRectangleShape *hitbox_sprite2 = NULL;
    int error = 0;

    if (!sprite_1 || !sprite_2)
        return (84);
    hitbox_sprite1 = init_hitbox_square(sprite_1);
    hitbox_sprite2 = init_hitbox_square(sprite_2);
    if (!hitbox_sprite1 || !hitbox_sprite2)
        return (84);
    error = \
    is_collision_square_without_rotation(hitbox_sprite1, hitbox_sprite2);
    free_hitbox_square(hitbox_sprite1);
    free_hitbox_square(hitbox_sprite2);
    return (error);
}

int check_if_collision_btw_circle_square(int const radius\
, sfSprite *const sprite_circle, sfSprite *const sprite_square)
{
    sfCircleShape *hitbox_circle = NULL;
    sfRectangleShape *hitbox_square = NULL;
    int error = 0;

    if (!sprite_circle || !sprite_square)
        return (84);
    hitbox_circle = init_hitbox_circle(radius, sprite_circle);
    hitbox_square = init_hitbox_square(sprite_square);
    if (!hitbox_circle || !hitbox_square)
        return (84);
    error = is_collision_circle_square(hitbox_circle, hitbox_square, radius);
    free_hitbox_circle(hitbox_circle);
    free_hitbox_square(hitbox_square);
    return (error);
}