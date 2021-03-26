/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** draw_projectile
*/

#include "projectile.h"

#include <SFML/Graphics/RenderWindow.h>

void draw_projectile(sfRenderWindow *win, projectile_t basic_projectile)
{
    if (basic_projectile.state == shooted) {
        sfRenderWindow_drawSprite(win, basic_projectile.spt_projectile, NULL);
    }
}