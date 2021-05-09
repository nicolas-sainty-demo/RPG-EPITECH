/*
** EPITECH PROJECT, 2020
** map_creator_tool
** File description:
** window_fonction
*/

#ifndef WINDOW_FONCTION_H_
#define WINDOW_FONCTION_H_

#include "window_struc.h"

the_window init_window(const int x, const int y);
void speed_of_game(float s);
int default_page(the_window *windows);

float time_to_float(sfClock *time);

void draw_heal_bar(sfVector2f size, sfVector2f heal_min_max, \
sfVector2f position, sfRenderWindow *window);

#endif /* !WINDOW_FONCTION_H_ */
