/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** button
*/

#ifndef BUTTON_H_
#define BUTTON_H_

#define MENU_BUTTON "res/win_menu/reset_win_menu.png"
#define EXIT_BUTTON "res/win_menu/resit_exit.png"
#define POS_RESET (sfVector2f){-180, -100}
#define POS_EXIT (sfVector2f){-180, 30}

#define SETTING "res/menu/fonts/menu.png"
#define B_EXIT "res/dead_menu/resit_exit.png"
#define B_UP "res/dead_menu/dede.png"
#define B_DOWN "res/dead_menu/moins.png"
#define NB_BUTTON 3

#define NB_SPRITE 2
#define BACKGRND "res/menu/fonts/background.png"
#define B_PLAY "res/dead_menu/resume.png"
#define B_EXIT "res/dead_menu/resit_exit.png"
#define B_SETTING "res/dead_menu/settings.png"
#define NB_BUTTON 3

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