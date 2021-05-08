/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** game
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
#include "particules.h"
#include "gameplay/inventory.h"
#include "ennemies.h"
#include "dead_menu.h"
#include "pause.h"
#include "main_menu.h"

float speek\
(the_window *windows, char **conversation, entity_passive_t *passif);

bool is_collision_proj_ennemy(the_window *window);

void print_item(the_window *windows);

void update_the_particules(projectile_t **proj);

void update_particules_for_player(player_t *player);

void pick_the_item(the_window *windows);

void draw_player(the_window *windows);

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
    draw_player(windows);
}

static void update(the_window *windows)
{
    if (windows->scene->player->hp <= 0) {
        windows->state = in_death_menu;
    }
    update_all_projectiles(windows->scene->player->proj);
    update_ennemies(windows);
    sfRenderWindow_setView(windows->window, windows->camera);
    anim_player(windows->scene->player);
    move_player(windows);
    update_particules_for_player(windows->scene->player);
    update_the_particules(windows->scene->player->proj);
    draw(windows);
}

static void is_change_scene(the_window *windows)
{
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyE)
        windows->state = in_inventory;
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyTab)
        windows->state = in_pause;
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyF)
        windows->usekey = sfTrue;
}

static void handle_event(the_window *windows)
{
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        event_projectile(windows->event, windows->scene->player->proj\
        , windows);
        is_change_scene(windows);
    }
}

void gameplay_scene(the_window *windows)
{
    update(windows);
    is_collision_proj_ennemy(windows);
    path_finding(windows);
    pick_the_item(windows);
    for (int i = 0; windows->scene->passive[i]; i += 1) {
        sfRenderWindow_drawSprite(windows->window\
        , windows->scene->passive[i]->sprite, NULL);
        anim_passive(windows->scene->passive[i]);
        if (check_if_collision_btw_square_without_rotation\
        (windows->scene->passive[i]->sprite, windows->scene->player->sprite) \
        && windows->usekey == sfTrue)
            speek(windows, windows->scene->passive[i]->conversation\
            ,  windows->scene->passive[i]);
    }
    windows->usekey = sfFalse;
    handle_event(windows);
}