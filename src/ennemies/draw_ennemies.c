/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** draw_ennemies
*/

#include "projectile.h"
#include "window_struc.h"

void show_healbar(the_window *windows, int const i);

static void drawn_ennemies_info(the_window *windows, int i)
{
    if (windows->scene->enemy[i]->hp != \
    windows->scene->enemy[i]->hp_max && windows->scene->enemy[i]->hp > 0)
        show_healbar(windows, i);
    if (windows->scene->enemy[i]->type)
        draw_projectile(windows->window, windows->scene->enemy[i]->proj);
}

void draw_ennemies(the_window *windows)
{
    for (int i = 0; windows->scene->enemy[i]; i += 1) {
        sfRenderWindow_drawSprite\
        (windows->window, windows->scene->enemy[i]->sprite, NULL);
        anim_enemy(windows->scene->enemy[i]);
        if (windows->scene->enemy[i]->speed_vector.x >= 0) {
            windows->scene->enemy[i]->flip = sfFalse;
        } else
            windows->scene->enemy[i]->flip = sfTrue;
        drawn_ennemies_info(windows, i);
    }
}