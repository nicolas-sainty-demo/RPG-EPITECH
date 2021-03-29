/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_player_colition_map
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "map.h"
#include "collision.h"
#include <SFML/Graphics/RectangleShape.h>
#include <stdlib.h>

sfVector2i get_position_render_map\
(sfVector2f pos_in_window, map_t *map, sfVector2i origine_decalage)
{
    sfVector2f size = sfSprite_getScale(map->layer_b);
    sfVector2i posei = {(pos_in_window.x + origine_decalage.x) / (16 * size.x)\
    , (pos_in_window.y + origine_decalage.y) / (16 * size.y)};
    return (posei);
}

void get_feet_vector\
(scene_t *scene, sfVector2i *feet_right, sfVector2i *feet_left_top)
{
    *feet_right = \
    get_position_render_map(sfSprite_getPosition(scene->player->sprite), \
    scene->map, \
    (sfVector2i){64, 70});
    *feet_left_top = \
    get_position_render_map(sfSprite_getPosition(scene->player->sprite), \
    scene->map, \
    (sfVector2i){0, 50});
}

int player_colition_map(scene_t *scene)
{
    sfVector2i feet_right = {0};
    sfVector2i feet_left_top = {0};

    get_feet_vector(scene, &feet_right, &feet_left_top);
    for (int y = feet_left_top.y; y <= feet_right.y; y += 1)
        for (int x = feet_left_top.x; x <= feet_right.x; x += 1) {
            if (scene->map->tils_colition[y][x] != 1)
                return (0);
        }
    return (1);
}