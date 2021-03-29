/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "map.h"
#include "projectile.h"

#include <stdlib.h>

static void draw(the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    draw_map(windows->window, windows->scene->map, 16);
    sfRenderWindow_drawSprite\
    (windows->window, windows->scene->player->sprite, NULL);
}

static void update(the_window *windows)
{
    draw(windows);
}

void default_page(the_window *windows)
{
    projectile_t **proj = init_tab_projectile("res/projectile/bullet.png", 20, 10, NB_OF_MUN_);

    while (sfRenderWindow_isOpen(windows->window)) {
        speed_of_game((float)1/60);
        update(windows);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
            event_projectile(windows->event, windows->window, proj);
        }
        update_all_projectiles(proj);
        draw_all_projectiles(windows->window, proj);
        sfRenderWindow_display(windows->window);
    }

}