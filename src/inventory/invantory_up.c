/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** invantory_up
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "gameplay/inventoryfile.h"
#include "key.h"
#include "selec_space.h"
#include <stdio.h>
#include "str.h"

void draw_invantory_(the_window *windows, const int position_cursor\
, char **item_select, const int key_press);

void event_interaction_iventory(the_window *windows, int *key_press);

int event_movement_cursor(the_window *windows);

void init_inventory(inventory *inv)
{
    inv->inventory_texture = sfTexture_createFromFile
    ("res/inventory/inventaire_rpg.png", NULL);
    inv->inventory_sprite = sfSprite_create();
    sfSprite_setTexture\
    (inv->inventory_sprite, inv->inventory_texture, sfTrue);
    inv->inventory_te_item = sfTexture_createFromFile
    ("res/inventory/test_item.png", NULL);
    inv->inventory_sp_item = sfSprite_create();
    sfSprite_setTexture\
    (inv->inventory_sp_item, inv->inventory_te_item, sfTrue);
}

void set_and_draw(the_window *windows, const int position_cursor, \
char **item_select, const int key_press)
{
    sfSprite_setOrigin(windows->inv->inventory_sprite, (sfVector2f){452, 323});
    sfRenderWindow_clear(windows->window, sfBlack);
    sfSprite_setPosition\
    (windows->inv->inventory_sprite, windows->inv->pos_inv);
    sfRenderWindow_drawSprite\
    (windows->window, windows->inv->inventory_sprite, NULL);
    draw_invantory_(windows, position_cursor, item_select, key_press);
    sfSprite_setTextureRect(windows->inv->inventory_sp_item, (sfIntRect)\
    {(**item_select - 33) * 90, 0, 90, 90});
    sfSprite_setPosition(windows->inv->inventory_sp_item, selec_space);
    sfRenderWindow_drawSprite\
    (windows->window, windows->inv->inventory_sp_item, NULL);
    sfRenderWindow_display(windows->window);
}

void verif_key(the_window *windows, int *key_press)
{
    if (windows->event.type == sfEvtKeyPressed) {
        if (windows->event.key.code == sfKeyE)
            windows->state = in_game;
        if (windows->event.key.code == sfKeyA)
            *key_press = SELECT_KEY;
        event_interaction_iventory(windows, key_press);
    }
}

int cursor_move(the_window *windows)
{
    if (windows->event.type == sfEvtClosed)
        sfRenderWindow_close(windows->window);
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyD)
        return (1);
    return (event_movement_cursor(windows));
}