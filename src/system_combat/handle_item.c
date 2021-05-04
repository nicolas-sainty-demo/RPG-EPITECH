/*
** EPITECH PROJECT, 2021
** $
** File description:
** drop_item
*/

#include "window_struc.h"
#include "collision.h"
#include <malloc.h>

items_t *is_item_in_range(the_window *windows)
{
    items_t *tmp_head = windows->scene->pos_items;

    while (tmp_head) {
        if (check_if_square_contains_point\
        (windows->scene->player->sprite, tmp_head->pos))
            return (tmp_head);
        tmp_head = tmp_head->next;
    }
    return (NULL);
}

void print_item(the_window *windows)
{
    items_t *tmp_head = windows->scene->pos_items;

    while (tmp_head) {
        sfSprite_setTextureRect(windows->inv->inventory_sp_item, \
        (sfIntRect) {(tmp_head->type - 33) * 90, 0, 90, 90});
        sfSprite_setPosition(windows->inv->inventory_sp_item, tmp_head->pos);
        sfRenderWindow_drawSprite\
        (windows->window, windows->inv->inventory_sp_item, NULL);
        tmp_head = tmp_head->next;
    }
}

void free_items(items_t *head)
{
    items_t *tmp = head;

    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}