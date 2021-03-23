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
    sfSprite *sprite;
    unsigned char **tils;
    char **tils_colition;
} map_t;


#endif /* !MAP_H_ */
