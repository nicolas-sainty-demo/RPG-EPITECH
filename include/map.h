/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_
#define tils_size 16

#include <SFML/Graphics/Sprite.h>

typedef struct map
{
    sfSprite *layer_a;
    sfSprite *layer_b;
    sfSprite *layer_c;
    char **map_layer_a;
    char **map_layer_b;
    char **map_layer_c;
    char **tils_colition;
} map_t;

typedef struct map_draw
{
    sfVector2f size;
    sfVector2i middel;
    int x;
    int y;
} map_draw_t;

#endif /* !MAP_H_ */
