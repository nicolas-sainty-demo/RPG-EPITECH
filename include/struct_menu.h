/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** menu
*/

#ifndef MENU_H_
#define MENU_H_

#include <SFML/Graphics/Sprite.h>

#include "struct_button.h"

typedef enum sprite_menu_s
{
    background_menu,
    background_setting
} sprite_menu_t;

typedef enum button_menu_s
{
    play,
    settings,
    exit,
    up_volume,
    down_volume
} button_menu_t;

typedef struct main_menu_s
{
    sfSprite **sprites;
    sfTexture **texture;
    struct_button_t **button;
} main_menu_t;

#endif /* !MENU_H_ */