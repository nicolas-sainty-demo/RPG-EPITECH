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

#define PARTICl_RAND (sfVector2f){0, 360}

float speek\
(the_window *windows, char **conversation, entity_passive_t *passif);

bool is_collision_proj_ennemy(the_window *window);

void print_item(the_window *windows);

void draw_heal_bar_player(player_t *player, the_window *window)
{
    sfVector2f heal_min_max = {player->hp, player->hp_max};
    sfVector2i pos = {30, 30};

    sfVector2f pos_2 = \
    sfRenderWindow_mapPixelToCoords(window->window, pos, window->camera);
    draw_heal_bar((sfVector2f){200, 50}, heal_min_max, pos_2, window->window);
}

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
    for (int i = 0; windows->scene->player->proj[i]; i++) {
        sfRenderWindow_drawPrimitives(windows->window, windows->scene->player->proj[i]->particl.m_vertices,\
            windows->scene->player->proj[i]->particl.nb_particules, sfPoints, NULL);
    }
    sfRenderWindow_drawPrimitives(windows->window, \
    windows->scene->player->particl.m_vertices, windows->scene->player->particl.nb_particules, sfPoints, NULL);
    draw_heal_bar_player(windows->scene->player, windows);
}

void update_the_particules(projectile_t **proj)
{
    sfTime elapsed;
    int i = 0;
    particules_t particl;

    while (proj[i]) {
        particl = proj[i]->particl;
        elapsed = sfClock_restart(proj[i]->particl.clock);
        if (proj[i]->state == reload) {
            update_particules(elapsed, &particl, proj[i]->init_pos, PARTICl_RAND);
        }
        i++;
    }
}

void update_particules_for_player(player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite);
    sfFloatRect bound_p = sfSprite_getGlobalBounds(player->sprite);
    sfTime elapsed = sfClock_restart(player->particl.clock);
    static int is_reset = 0;

    pos.x += bound_p.width/2;
    pos.y += bound_p.height;
    if (player->anime != player_stay) {
        update_particules_player(elapsed, &player->particl, pos, PARTICl_RAND);
        is_reset = 0;
    }
    else if (player->anime == player_stay && is_reset == 0) {
        is_reset = 1;
        for (unsigned int i = 0; i < player->particl.nb_particules; i++) {
            reset_particule_player(&player->particl, i, PARTICl_RAND);        
        }
    }
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

void pick_the_item(the_window *windows)
{
    items_t *item = is_item_in_range(windows);
    int i = 0;

    if (item == NULL)
        return;
    while (windows->scene->player->inventaire[i] != '\0' \
    && windows->scene->player->inventaire[i] != '!') {
        i += 1;
    }
    if (i >= 20) {
        return;
    }
    windows->scene->player->inventaire[i] = item->type;
    delete_node(&windows->scene->pos_items, item);
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
            speek(windows, windows->scene->passive[i]->conversation,  windows->scene->passive[i]);
    }
    windows->usekey = sfFalse;
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        event_projectile(windows->event, windows->scene->player->proj,\
         windows);
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
}