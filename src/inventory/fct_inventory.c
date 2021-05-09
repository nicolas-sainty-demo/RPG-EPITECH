/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** fct_inventory
*/

#include "key.h"

void check_drop_key(const int key_press, char *item_select)
{
    if (key_press == DROP_KEY)
        *item_select = '!';
}