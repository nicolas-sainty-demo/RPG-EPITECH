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
void free_button(struct_button_t *button);
void update_tab_button(the_window *p, struct_button_t *button, int const nb);
void button_tab_event(the_window *p, struct_button_t *button, int const nb);
void button_tab_draw(the_window *p, struct_button_t *button, int const nb);
void button_tab_free(struct_button_t *button, int const nb);

#endif /* !BUTTON_H_ */