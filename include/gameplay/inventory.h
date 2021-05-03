/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** inventory
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include "window_struc.h"
#include "inventory_struct.h"

inventory *init_struct();
float inventory_scene(int **tab_stock, the_window *win);

#endif /* !INVENTORY_H_ */
