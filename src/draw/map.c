/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** map
*/

#include "map.h"
#include <stdlib.h>

void draw_map\
(const sfRenderWindow *window, const map_t *map, const int tils_size)
{
    sfVector2f size = sfSprite_getScale(map->sprite_sol);

    for (int i = 0; map->sol[i] != NULL; i++) {
        if (i * (tils_size * size.y) > 1080)
                break;
        for (int k = 0; map->sol[i][k] != '\0'; k++) {
            if (k * (tils_size * size.x) > 1920)
                break;
            sfSprite_setPosition(map->sprite_sol, \
            (sfVector2f){(k * (tils_size * size.x)), \
            (i * (tils_size * size.y))});
            sfSprite_setTextureRect(map->sprite_sol, (sfIntRect)\
            {(map->sol[i][k] - 48) * tils_size, 0, tils_size, tils_size});
            sfRenderWindow_drawSprite(window, map->sprite_sol, NULL);
        }
    }
}