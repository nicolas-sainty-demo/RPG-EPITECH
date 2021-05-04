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
#include "text.h"

float speek(the_window *windows, char **conversation);

bool is_collision_proj_ennemy(the_window *window);

void print_item(the_window *windows);

void ennemies_deal_damage(entity_enemy_t *ennemies, player_t *player);

void draw_heal_bar_player(player_t *player, the_window *window)
{
    sfVector2f heal_min_max = {player->hp, player->hp_max};
    sfVector2i pos = {30, 30};

    sfVector2f pos_2 = sfRenderWindow_mapPixelToCoords(window->window, pos, window->camera);
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
        if (check_if_collision_btw_square_without_rotation\
        (windows->scene->passive[i]->sprite, windows->scene->player->sprite) \
        && windows->usekey == sfTrue)
            speek(windows, windows->scene->passive[i]->conversation);
    }
    print_item(windows);
    draw_all_projectiles(windows->window, windows->scene->player->proj);
    draw_heal_bar_player(windows->scene->player, windows);
}

static void update(the_window *windows)
{
    update_all_projectiles(windows->scene->player->proj);
    update_ennemies(windows);
    for (int i = 0; windows->scene->enemy && windows->scene->enemy[i]; i++) {
        sfSprite_setPosition(windows->scene->enemy[i]->sprite\
        , windows->scene->enemy[i]->current_pos);
        ennemies_deal_damage(windows->scene->enemy[i], windows->scene->player);
        
    }
    sfRenderWindow_setView(windows->window, windows->camera);
    anim_player(windows->scene->player);
    move_player(windows);
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
        printf("FULL\n");
        return;
    }
    windows->scene->player->inventaire[i] = item->type;
    delete_node(&windows->scene->pos_items, item);
}

void default_page(the_window *windows)
{
    int **tab;

    windows->usekey = sfFalse;
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
        pick_the_item(windows);
        windows->usekey = sfFalse;
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
            event_projectile(windows->event, windows->scene->player->proj,\
             windows);
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyE) {
                windows->state = 1;
            }
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyF)
                windows->usekey = sfTrue;
        }
        is_collision_proj_ennemy(windows);
        path_fining(windows);
        sfRenderWindow_display(windows->window);
    }
    free_projectile(windows->scene->player->proj);
}