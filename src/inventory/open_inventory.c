/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** open_inventory
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "gameplay/inventoryfile.h"
#include "key.h"
#include "list.h"
#include <stdio.h>
#include "str.h"

void draw_invantory_(the_window *windows, const int position_cursor\
, char **item_select, const int key_press);

int cursor_move(the_window *windows);

void verif_key(the_window *windows, int *key_press);

void set_and_draw(the_window *windows, const int position_cursor, \
char **item_select, const int key_press);

void init_inventory(inventory *inv);

void switch_in_invantory(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void use_and_drop_item(const int key_press, char *item_select\
, the_window *windows, int position_cursor)
{
    if (key_press == DROP_KEY)
        *item_select = '!';
    if (key_press == USE_KEY)
        switch_in_invantory(item_select\
        , &windows->scene->player->inventaire[position_cursor]);
    if (key_press == EAT_KEY) {
        if (c_is_in_str(*item_select, food_list)) {
            *item_select = '!';
        }
    }
}

void invantory_word(the_window *windows)
{
    int position_cursor = 0;
    char *item_select = &windows->scene->player->inventaire[0];
    int key_press = 0;

    while (windows->state == in_inventory && \
    sfRenderWindow_isOpen(windows->window)) {
        set_and_draw(windows, position_cursor, &item_select, key_press);
        use_and_drop_item(key_press, item_select, windows, position_cursor);
        key_press = 0;
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            position_cursor += cursor_move(windows);
            verif_key(windows, &key_press);
        }
        if (position_cursor < 0 || position_cursor > 21)
            position_cursor = 0;
    }
}

float inventory_scene(the_window *windows)
{
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);

    invantory_word(windows);
    sfView_setCenter(windows->camera, camera_center);
    float save = time_to_float(timed);
    windows->state = in_game;
    return (save);
}