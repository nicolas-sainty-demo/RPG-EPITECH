/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** drop_items
*/

#include "window_struc.h"
#include <malloc.h>
#include <stdlib.h>

items_t *create_node(sfVector2f new_pos)
{
    items_t *item = malloc(sizeof(items_t));
    static int random = 0;
    int nb = rand() % 3;
    char string[] = {34, 35, 36, 37, 38, 39, 40};

    while (random == nb)
        nb = rand() % 3;
    if (!item)
        return (NULL);
    item->next = NULL;
    item->pos = new_pos;
    item->type = string[nb];
    random = nb;
    return (item);
}

int add_node(items_t **tab_pos, sfVector2f new_pos)
{
    items_t *new_node = create_node(new_pos);
    items_t *tmp_head = *tab_pos;
    int i = 0;

    if (!new_node)
        return (84);
    while (tmp_head && tmp_head->next) {
        tmp_head = tmp_head->next;
    }
    if (tmp_head)
        tmp_head->next = new_node;
    else
        *tab_pos = new_node;
    return (1);
}

void delete_node(items_t **pos_items, items_t *to_del)
{
    items_t *tmp_head = *pos_items;

    if (tmp_head == to_del && !tmp_head->next) {
        *pos_items = NULL;
        free(to_del);
        return;
    }
    if (tmp_head == to_del && tmp_head->next) {
        *pos_items = tmp_head->next;
        free(to_del);
        return;
    }
    while (tmp_head->next != to_del)
        tmp_head = tmp_head->next;
    if (to_del)
        tmp_head->next = to_del->next;
    free(to_del);
}

int drop_the_item(items_t **pos_items, sfSprite *sprite)
{
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfFloatRect b = sfSprite_getGlobalBounds(sprite);

    pos.x += b.width/2;
    pos.y += b.height/2;
    if (add_node(pos_items, pos) == 84)
        return (84);
    return (0);
}