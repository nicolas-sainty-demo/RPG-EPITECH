/*
** EPITECH PROJECT, 2021
** $
** File description:
** drop_item
*/

#include "window_struc.h"

void print_item(the_window *windows)
{
    for (int j = 0; windows->scene->pos_items && windows->scene->pos_items[j]; j++) {
        printf("\n{\nx-->%f, y-->%f\n}", windows->scene->pos_items[j]->x, windows->scene->pos_items[j]->y);
    }
    for (int i = 0; windows->scene->pos_items && windows->scene->pos_items[i]; i++) {
        // sfSprite_setTextureRect(windows->inv->inventory_sp_item, (sfIntRect) {(windows->scene->player->inventaire[i] - 33) * 90, 0, 90, 90});
        
        if (windows->inv->inventory_sp_item) {
            sfSprite_setPosition(windows->inv->inventory_sp_item, *windows->scene->pos_items[i]);
            sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sp_item, NULL);
        }
    }
}