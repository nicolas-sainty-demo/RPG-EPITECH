/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_secondary
*/

#include <malloc.h>
#include "str.h"
#include "map.h"
#include "window_struc.h"

void free_map(map_t *map)
{
    sfSprite_destroy(map->layer_a);
    sfSprite_destroy(map->layer_b);
    sfSprite_destroy(map->layer_c);
    free_char_tab(map->map_layer_a);
    free_char_tab(map->map_layer_b);
    free_char_tab(map->map_layer_c);
    free_char_tab(map->tils_colition);
}

void free_items_on_ground(items_t **item)
{
    items_t *current = (*item);

    while ((*item)) {
        current = (*item);
        (*item) = (*item)->next;
        free(current);
    }
    *item = NULL;
}