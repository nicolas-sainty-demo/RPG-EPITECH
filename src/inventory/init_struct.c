/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_struct
*/

#include "gameplay/inventory.h"

inventory *init_struct(void)
{
    inventory *inv = malloc(sizeof(inventory));
    inv->pos_inv.x = 0;
    inv->pos_inv.y = 0;
    return (inv);
}