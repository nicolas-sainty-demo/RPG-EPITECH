/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** ennemies
*/

#ifndef ENNEMIES_H_
#define ENNEMIES_H_

#include <SFML/Graphics/RenderWindow.h>

#include "window_struc.h"

#define SIZE_BAR_HEAL (sfVector2f){100, 30}

void draw_heal_bar(sfVector2f size, sfVector2f heal_min_max, \
sfVector2f position, sfRenderWindow *window);

void draw_ennemies(the_window *windows);

void update_ennemies(the_window *windows);

void path_finding(the_window *windows);

#endif /* !ENNEMIES_H_ */
