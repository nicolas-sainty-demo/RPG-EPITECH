/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include <stdbool.h>
#include "window_struc.h"
#include "window_fonction.h"
#include "map.h"
#include "collision.h"
#include "move.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/View.h>
#include "projectile.h"
#include <stdlib.h>
#include "draw.h"
#include "from_file.h"

#include "gameplay/inventory.h"
#include "ennemies.h"

bool is_collision_proj_ennemy(the_window *window);

void print_item(the_window *windows);

static void draw(the_window *windows)
{
    draw_map(windows, windows->scene->map);
    sfRenderWindow_drawSprite\
    (windows->window, windows->scene->player->sprite, NULL);
    draw_ennemies(windows);
    for (int i = 0; windows->scene->passive[i]; i += 1) {
        sfRenderWindow_drawSprite(windows->window\
        , windows->scene->passive[i]->sprite, NULL);
        anim_passive(windows->scene->passive[i]);
    }
    print_item(windows);
    draw_all_projectiles(windows->window, windows->scene->player->proj);
}

static void update(the_window *windows)
{
    update_all_projectiles(windows->scene->player->proj);
    update_ennemies(windows);
    sfRenderWindow_setView(windows->window, windows->camera);
    anim_player(windows->scene->player);
    move_player(windows);
    draw(windows);
}

void default_page(the_window *windows)
{
    int **tab;
    windows->state = 0;
    windows->scene = get_scene_from_folder("res/scene/debut");
    windows->scene->pos_items = NULL;

    while (sfRenderWindow_isOpen(windows->window)) {
        sfRenderWindow_clear(windows->window, sfBlack);
        speed_of_game((float)1/60);
        if (windows->state == 0) {
            sfRenderWindow_clear(windows->window, sfBlack);
            update(windows);
        } else if (windows->state == 1) {
            inventory_scene(tab, windows);
            windows->state = 0;
        }
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
            event_projectile(windows->event, windows->scene->player->proj,\
             windows);
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyE) {
                windows->state = 1;
            }
        }
        is_collision_proj_ennemy(windows);
        sfRenderWindow_display(windows->window);
    }
    free_projectile(windows->scene->player->proj);
}