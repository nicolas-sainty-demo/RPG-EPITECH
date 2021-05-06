/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#include "window_struc.h"

struct_button_t init_button(void (*ptr) (void *), char *path, sfVector2f pos);
void update_button(the_window *p, struct_button_t *button);
void button_event(the_window *p, struct_button_t *button);
void button_event(the_window *p, struct_button_t *button);
void update_tab_button(the_window *p, struct_button_t ***button);
void button_tab_event(the_window *p, struct_button_t ***button);

#endif /* !BUTTON_H_ */