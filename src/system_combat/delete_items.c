/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** delete_items
*/

#include <malloc.h>
#include <stdlib.h>
#include "window_struc.h"

static int delete_node_special_conditions(items_t **pos_items\
, items_t *to_del, items_t *tmp_head)
{
    if (tmp_head == to_del && !tmp_head->next) {
        *pos_items = NULL;
        free(to_del);
        return (1);
    }
    if (tmp_head == to_del && tmp_head->next) {
        *pos_items = tmp_head->next;
        free(to_del);
        return (1);
    }
    return (0);
}

void delete_node(items_t **pos_items, items_t *to_del)
{
    items_t *tmp_head = *pos_items;

    if (delete_node_special_conditions(pos_items, to_del, tmp_head))
        return;
    while (tmp_head->next != to_del)
        tmp_head = tmp_head->next;
    if (to_del)
        tmp_head->next = to_del->next;
    free(to_del);
}