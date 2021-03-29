/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** heal_bare
*/

#include "window_struc.h"
#include <SFML/Graphics/RectangleShape.h>

void draw_heal_bar(sfVector2f size, sfVector2f heal_min_max, \
sfVector2f position, sfRenderWindow *window)
{
    sfRectangleShape *healbar = sfRectangleShape_create();
    sfRectangleShape *heal = sfRectangleShape_create();

    sfRectangleShape_setFillColor(heal, sfGreen);
    sfRectangleShape_setFillColor(healbar, sfRed);
    sfRectangleShape_setSize(healbar, size);
    sfRectangleShape_setSize(heal, (sfVector2f)\
    {(size.x * heal_min_max.x) / heal_min_max.y, size.y});
    sfRectangleShape_setPosition(healbar, position);
    sfRectangleShape_setPosition(heal, position);
    sfRenderWindow_drawRectangleShape(window, healbar, NULL);
    sfRenderWindow_drawRectangleShape(window, heal, NULL);
    sfRectangleShape_destroy(healbar);
    sfRectangleShape_destroy(heal);
}