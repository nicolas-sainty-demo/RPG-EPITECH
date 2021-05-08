/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** win_windows
*/

#include "window_fonction.h"
#include "gameplay/win_menu.h"
#include <stdio.h>
#include "button.h"

#define MENU_BUTTON "res/win_menu/reset_win_menu.png"
#define EXIT_BUTTON "res/win_menu/resit_exit.png"
#define POS_RESET (sfVector2f){-180, -100}
#define POS_EXIT (sfVector2f){-180, 30}

void go_menu(void *ptr);

void go_exit(void *ptr);

void init_win_menu(win_me *w_menu);

static void set_and_pos_win(the_window *windows)
{
    sfVector2f pos = {-960, -555};
    sfRenderWindow_clear(windows->window, sfBlack);

    sfSprite_setPosition(windows->w_menu->w_menu_sprite, pos);
    sfRenderWindow_drawSprite(windows->window, \
    windows->w_menu->w_menu_sprite , NULL);
}

static void is_click(the_window *windows)
{
    if (windows->event.type == sfEvtMouseButtonPressed)
        windows->click = sfTrue;
    else
        windows->click = sfFalse;
}

void win_loop(the_window *windows, struct_button_t *button_menu\
, struct_button_t *button_ext)
{
    update_button(windows, button_menu);
    update_button(windows, button_ext);
    set_and_pos_win(windows);
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        is_click(windows);
        button_event(windows, button_menu);
        button_event(windows, button_ext);
    }
    sfRenderWindow_drawSprite(windows->window, button_menu->sprite, NULL);
    sfRenderWindow_drawSprite(windows->window, button_ext->sprite, NULL);
    sfRenderWindow_display(windows->window);
}

static void free_res_win_menu\
(struct_button_t button_menu, struct_button_t button_ext, sfClock *timed)
{
    sfSprite_destroy(button_menu.sprite);
    sfTexture_destroy(button_menu.texture);
    sfSprite_destroy(button_ext.sprite);
    sfTexture_destroy(button_ext.texture);
    sfClock_destroy(timed);
}

float win_menu(the_window *windows)
{
    struct_button_t button_menu = init_button\
    (&go_menu, MENU_BUTTON, POS_RESET);
    struct_button_t button_ext = init_button(&go_exit, EXIT_BUTTON, POS_EXIT);
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    float time = 0;
    windows->click = sfFalse;

    if (!button_menu.sprite || !button_ext.sprite || !timed)
        return (-1);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);
    while (windows->state == in_win && sfRenderWindow_isOpen(windows->window))
        win_loop(windows, &button_menu, &button_ext);
    sfView_setCenter(windows->camera, camera_center);
    time = time_to_float(timed);
    free_res_win_menu(button_menu, button_ext, timed);
    return (time);
}