/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "map.h"
#include "collision.h"
#include "move.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/View.h>
#include <stdlib.h>
#include "draw.h"
#include "from_file.h"


static void draw(the_window *windows)
{
    sfRenderWindow_display(windows->window);
    sfRenderWindow_clear(windows->window, sfBlack);
}

static void update(the_window *windows)
{
    draw(windows);
}

void default_page(the_window *windows)
{
    windows->scene = get_scene_from_folder("res/scene/debut");

    while (sfRenderWindow_isOpen(windows->window)) {
        sfRenderWindow_setView(windows->window, windows->camera);
        draw_map(windows, windows->scene->map);
        sfRenderWindow_drawSprite\
        (windows->window, windows->scene->player->sprite, NULL);
        for (int i = 0; windows->scene->enemy[i]; i += 1) {
            sfRenderWindow_drawSprite(windows->window, windows->scene->enemy[i]->sprite, NULL);
            anim_enemy(windows->scene->enemy[i]);
        }
        for (int i = 0; windows->scene->passive[i]; i += 1) {
            sfRenderWindow_drawSprite(windows->window, windows->scene->passive[i]->sprite, NULL);
            anim_passive(windows->scene->passive[i]);
        }
        anim_player(windows->scene->player);
        move_player(windows);
        speed_of_game((float)1/60);
        update(windows);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
        }
    }
}