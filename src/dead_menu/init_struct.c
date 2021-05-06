/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_struct
*/

#include "gameplay/dead_menu.h"
#include <malloc.h>

dead_me *init_struct_dead_menu(void)
{
    dead_me *d_menu = malloc(sizeof(dead_me));

    if (!d_menu)
        return (NULL);
    d_menu->pos_menu.x = 0;
    d_menu->pos_menu.y = 0;
    return (d_menu);
}