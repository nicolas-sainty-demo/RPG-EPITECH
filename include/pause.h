/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** pause
*/

#ifndef PAUSE_H_
#define PAUSE_H_

#include <SFML/Graphics/Sprite.h>
#include "window_struc.h"

struct pause_s
{
    sfSprite *sprite;
    sfTexture *texture;
};

float pause_menu(the_window *windows);

#endif /* !PAUSE_H_ */
