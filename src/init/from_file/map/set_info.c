/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** set_info
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include <dirent.h>
#include <sys/types.h>
#include "from_file.h"

static void get_sprite_layer(char **info, map_t *map)
{
    for (int i = 0; info[i] != NULL; i += 1) {
        if (my_strcmp_to_c(info[i], "layer_a", '='))
            map->layer_a = get_sprite_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "layer_b", '='))
            map->layer_b = get_sprite_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "layer_c", '='))
            map->layer_c = get_sprite_after_c(info[i], '=');
    }
}

static void recard_sprite(sfSprite *sprite, sfIntRect rec, sfVector2f size)
{
    if (sprite != NULL) {
        sfSprite_setTextureRect(sprite, rec);
        sfSprite_setScale(sprite, size);
    }
}

static void set_info_to_sprite(char **info, map_t *map)
{
    sfIntRect rec = {0, 0, 16, 16};
    sfVector2f size = {1, 1};

    for (int i = 0; info[i] != NULL; i += 1) {
        if (my_strcmp_to_c(info[i], "rec", '=')) {
            rec = get_sf_int_rect_after_c(info[i], '=');
        }
        if (my_strcmp_to_c(info[i], "size", '=')) {
            sfVector2i vector = get_the_vector_i_after_c(info[i], '=');
            size = (sfVector2f){(float)vector.x / 100, (float)vector.y / 100};
        }
    }
    recard_sprite(map->layer_a, rec, size);
    recard_sprite(map->layer_b, rec, size);
    recard_sprite(map->layer_c, rec, size);
}

void set_info(char **info, map_t *map)
{
    get_sprite_layer(info, map);
    set_info_to_sprite(info, map);
    free(info);
}