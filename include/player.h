/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics/Sprite.h>

typedef struct player
{
    char *inventaire;
    sfSprite *sprite;
    char anime;
    int hp;
} player_t;


#endif /* !PLAYER_H_ */
