/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** dead_menu
*/

#ifndef DEAD_MENU_H_
#define DEAD_MENU_H_

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include "window_struc.h"
#include "dead_menu_struct.h"

#define POS_RESET (sfVector2f){-180, -100}
#define POS_EXIT (sfVector2f){-180, 30}

dead_me *init_struct_dead_menu();
void init_dead_menu(dead_me *d_menu);
float dead_menu(the_window *windows);

#endif /* !DEAD_MENU_H_ */
