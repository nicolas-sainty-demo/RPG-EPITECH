/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** win_menu_struct
*/

#ifndef WIN_MENU_STRUCT_H_
#define WIN_MENU_STRUCT_H_

#include <SFML/Graphics.h>

typedef struct win_menu_s
{
    sfVector2f pos_menu;
    sfSprite *w_menu_sprite;
    sfTexture *w_menu_texture;
} win_me;

#endif /* !WIN_MENU_STRUCT_H_ */
