/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include <SFML/Graphics/Sprite.h>

typedef struct map
{
    sfSprite *sprite_sol;
    sfIntRect basic_rec;
    char **sol;
    char **tils_colition;
} map_t;

void draw_map\
(sfRenderWindow *window, const map_t *map, const int tils_size);

#endif /* !MAP_H_ */
