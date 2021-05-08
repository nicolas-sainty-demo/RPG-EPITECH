/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** win_menu
*/

#ifndef WIN_MENU_H_
#define WIN_MENU_H_

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>
#include "window_struc.h"
#include "win_menu_struct.h"

win_me *init_struct_win_menu();
void init_win_menu(win_me *w_menu);
float win_menu(the_window *windows);

#endif /* !WIN_MENU_H_ */