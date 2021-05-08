/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_struct
*/

#include "gameplay/dead_menu.h"
#include <malloc.h>

win_me *init_struct_win_menu(void)
{
    win_me *w_menu = malloc(sizeof(dead_me));

    if (!w_menu)
        return (NULL);
    w_menu->pos_menu.x = 0;
    w_menu->pos_menu.y = 0;
    return (w_menu);
}

void init_win_menu(win_me *w_menu)
{
    w_menu->w_menu_texture = sfTexture_createFromFile
    ("res/win_menu/win_rpg.png", NULL);
    w_menu->w_menu_sprite = sfSprite_create();
    sfSprite_setTexture(w_menu->w_menu_sprite, w_menu->w_menu_texture, sfTrue);
}