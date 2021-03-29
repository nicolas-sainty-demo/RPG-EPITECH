/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** map
*/

#include "map.h"
#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include "window_struc.h"

static void draw_x_render\
(map_draw_t info, char **map, sfSprite *sprite, sfRenderWindow *window)
{
    while (!(info.x * (tils_size * info.size.x) > info.middel.x + 960) \
    && map[info.y][info.x] != '\0') {
        if (map[info.y][info.x] != '0') {
            sfSprite_setPosition(sprite, \
            (sfVector2f){(info.x * (tils_size * info.size.x)), \
            (info.y * (tils_size * info.size.y))});
            sfSprite_setTextureRect(sprite, (sfIntRect)\
            {(map[info.y][info.x] - 48) * tils_size, 0, tils_size, tils_size});
            sfRenderWindow_drawSprite(window, sprite, NULL);
        }
        info.x += 1;
    }
}

static void draw_loop\
(map_draw_t info, char **map, sfSprite *sprite, sfRenderWindow *window)
{
    while (!(info.y * (tils_size * info.size.y) > info.middel.y + 540) \
    && map[info.y] != NULL) {
        info.x =  (info.middel.x - 960) / (tils_size * info.size.x);
        if (info.x < 0)
            info.x = 0;
        draw_x_render(info, map, sprite, window);
        info.y += 1;
    }
}

static void draw_a_layer\
(the_window *windows, char **map, sfSprite *sprite)
{
    map_draw_t info;
    info.size = sfSprite_getScale(sprite);
    info.middel = (sfVector2i)\
    {sfView_getCenter(windows->camera).x, sfView_getCenter(windows->camera).y};
    info.y = (info.middel.y - 540) / (tils_size * info.size.y);

    if (info.y < 0)
        info.y = 0;
    if (map == NULL || sprite == NULL)
        return;
    info.size = sfSprite_getScale(sprite);
    draw_loop(info, map, sprite, windows->window);
}

void draw_map\
(the_window *windows, map_t *map)
{
    draw_a_layer(windows, map->map_layer_a, map->layer_a);
    draw_a_layer(windows, map->map_layer_b, map->layer_b);
    draw_a_layer(windows, map->map_layer_c, map->layer_c);
}