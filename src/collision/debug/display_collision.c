/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** display_collision
*/

#include "collision.h"

#include <SFML/Graphics/CircleShape.h>

#include <SFML/Graphics/RectangleShape.h>

void display_circle_hitbox_debug(int const radius, sfSprite *sprite\
, sfRenderWindow *windows, sfColor color)
{
    sfCircleShape *circle = NULL;
    sfVector2f pos_sprite = { 0 };
    sfFloatRect boundary_sprite = { 0 };

    if (!sprite)
        return;
    circle = init_hitbox_circle(radius, sprite);
    if (!circle)
        return;
    boundary_sprite = sfSprite_getGlobalBounds(sprite);
    pos_sprite = sfSprite_getPosition(sprite);
    sfCircleShape_setPosition(circle, \
    (sfVector2f){pos_sprite.x+(boundary_sprite.width/2) - radius\
    , pos_sprite.y+(boundary_sprite.height/2) - radius});
    sfCircleShape_setFillColor(circle, color);
    sfRenderWindow_drawCircleShape(windows, circle, NULL);
    sfCircleShape_destroy(circle);
}

void display_square_hitbox_debug(sfSprite *sprite, sfRenderWindow *windows\
, sfColor color)
{
    sfRectangleShape *square = NULL;
    sfVector2f pos_sprite = { 0 };
    if (!sprite)
        return;

    square = init_hitbox_square(sprite);
    if (!square)
        return;
    pos_sprite = sfSprite_getPosition(sprite);
    sfRectangleShape_setPosition(square, pos_sprite);
    sfRectangleShape_setFillColor(square, color);
    sfRenderWindow_drawRectangleShape(windows, square, NULL);
    sfRectangleShape_destroy(square);
}