/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** inventory_struct
*/

#ifndef INVENTORY_STRUCT_H_
#define INVENTORY_STRUCT_H_

#include <SFML/Graphics.h>

typedef struct inventory_s
{
    int **tab_stock;
    sfVector2f pos_inv;
    sfVector2f tab_pos[22];
    sfSprite *inventory_sprite;
    sfSprite *inventory_sp_item;
    sfTexture *inventory_texture;
    sfTexture *inventory_te_item;
}inventory;

#endif /* !INVENTORY_STRUCT_H_ */