/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_hitbox_with_sprite
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/CircleShape.h>
#include <SFML/Graphics/Sprite.h>

sfRectangleShape *init_hitbox_square(sfSprite *const sprite)
{
    sfRectangleShape *hitbox_sprite = sfRectangleShape_create();
    sfFloatRect info_hitbox = { 0 };
    sfVector2f pos_sprite = { 0 };

    if (!hitbox_sprite || !sprite)
        return (NULL);
    pos_sprite = sfSprite_getPosition(sprite);
    info_hitbox = sfSprite_getGlobalBounds(sprite);
    sfRectangleShape_setSize(hitbox_sprite, (sfVector2f){info_hitbox.width\
    , info_hitbox.height});
    sfRectangleShape_setPosition(hitbox_sprite, pos_sprite);
    return (hitbox_sprite);
}

void free_hitbox_square(sfRectangleShape *hitbox_sprite)
{
    sfRectangleShape_destroy(hitbox_sprite);
}

sfCircleShape *init_hitbox_circle(int const radius, sfSprite *sprite)
{
    sfCircleShape *hitbox_circle = sfCircleShape_create();
    sfVector2f center_pos_sprite = { 0 };
    sfFloatRect boundary_sprite;

    if (!hitbox_circle || !sprite)
        return (NULL);
    center_pos_sprite = sfSprite_getPosition(sprite);
    boundary_sprite = sfSprite_getGlobalBounds(sprite);
    center_pos_sprite.x += (boundary_sprite.width/2);
    center_pos_sprite.y += (boundary_sprite.height/2);
    sfCircleShape_setRadius(hitbox_circle, radius);
    sfCircleShape_setFillColor(hitbox_circle, sfWhite);
    sfCircleShape_setPosition(hitbox_circle, (sfVector2f)
    {center_pos_sprite.x - radius, center_pos_sprite.y - radius});
    return (hitbox_circle);
}

void free_hitbox_circle(sfCircleShape *hitbox_circle)
{
    sfCircleShape_destroy(hitbox_circle);
}