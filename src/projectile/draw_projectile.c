/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** draw_projectile
*/

#include "projectile.h"

#include <SFML/Graphics/RenderWindow.h>

void draw_projectile(sfRenderWindow *win, projectile_t *const basic_projectile)
{
    if (basic_projectile->state == shooted) {
        sfRenderWindow_drawSprite(win, basic_projectile->spt_projectile, NULL);
    }
}

void draw_all_projectiles(sfRenderWindow *win\
, projectile_t *const *basic_projectile)
{
    for (int i = 0; basic_projectile[i] != NULL; i++) {
        draw_projectile(win, basic_projectile[i]);
    }
    
}