/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** drow_inventory
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "gameplay/inventoryfile.h"
#include "key.h"
#include "invantory_space.h"
#include <stdio.h>
#include "str.h"

void draw_invantory_(the_window *windows, const int position_cursor\
, char **item_select, const int key_press)
{
    for (int i = 0; i != 22; i++) {
        sfSprite_setTextureRect(windows->inv->inventory_sp_item, (sfIntRect)\
        {(windows->scene->player->inventaire[i] - 33) * 90, 0, 90, 90});
        sfSprite_setPosition\
        (windows->inv->inventory_sp_item, inventory_space[i]);
        sfRenderWindow_drawSprite\
        (windows->window, windows->inv->inventory_sp_item, NULL);
        if (i == position_cursor) {
            if (key_press == SELECT_KEY)
                *item_select = &windows->scene->player->inventaire[i];
            sfSprite_setTextureRect(windows->inv->inventory_sp_item\
            , (sfIntRect){(26) * 90, 0, 90, 90});
            sfRenderWindow_drawSprite\
            (windows->window, windows->inv->inventory_sp_item, NULL);
        }
    }
}