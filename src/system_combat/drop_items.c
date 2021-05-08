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

static void is_need_to_change_head(items_t **tab_pos\
, items_t *tmp_head, items_t *new_node)
{
    if (tmp_head)
        tmp_head->next = new_node;
    else
        *tab_pos = new_node;
}

int add_node(items_t **tab_pos, sfVector2f new_pos)
{
    items_t *new_node = create_node(new_pos);
    items_t *tmp_head = *tab_pos;

    if (!new_node)
        return (84);
    while (tmp_head && tmp_head->next) {
        tmp_head = tmp_head->next;
    }
    is_need_to_change_head(tab_pos, tmp_head, new_node);
    return (1);
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