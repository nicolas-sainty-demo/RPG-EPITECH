/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** dead_windows
*/

#include "window_fonction.h"
#include "gameplay/dead_menu.h"
#include <stdio.h>
#include "button.h"

void go_menu(void *ptr);

void go_exit(void *ptr);

void init_dead_menu(dead_me *d_menu)
{
    d_menu->d_menu_texture = sfTexture_createFromFile
    ("res/dead_menu/rpg_over.png", NULL);
    d_menu->d_menu_sprite = sfSprite_create();
    if (!d_menu->d_menu_texture || !d_menu->d_menu_sprite)
        return;
    sfSprite_setTexture(d_menu->d_menu_sprite, d_menu->d_menu_texture, sfTrue);
}

static void set_and_pos(the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    sfVector2f pos = {-960, -555};

    sfSprite_setPosition(windows->d_menu->d_menu_sprite, pos);
    sfRenderWindow_drawSprite(windows->window, \
    windows->d_menu->d_menu_sprite , NULL);
}

void dead_loop(the_window *windows, struct_button_t *button_menu\
, struct_button_t *button_ext)
{
    update_button(windows, button_menu);
    update_button(windows, button_ext);
    set_and_pos(windows);
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        if (windows->event.type == sfEvtMouseButtonPressed)
            windows->click = sfTrue;
        else
            windows->click = sfFalse;
        button_event(windows, button_menu);
        button_event(windows, button_ext);
    }
    sfRenderWindow_drawSprite(windows->window, button_menu->sprite, NULL);
    sfRenderWindow_drawSprite(windows->window, button_ext->sprite, NULL);
    sfRenderWindow_display(windows->window);
}

static void free_res(struct_button_t button_menu\
, struct_button_t button_ext, sfClock *timed)
{
    sfClock_destroy(timed);
    sfSprite_destroy(button_menu.sprite);
    sfTexture_destroy(button_menu.texture);
    sfSprite_destroy(button_ext.sprite);
    sfTexture_destroy(button_ext.texture);
}

float dead_menu(the_window *win)
{
    struct_button_t button_menu = init_button\
    (&go_menu, MENU_BUTTON, POS_RESET);
    struct_button_t button_ext = init_button(&go_exit, EXIT_BUTTON, POS_EXIT);
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(win->camera);
    win->click = sfFalse;
    float time = 0;

    sfView_setCenter(win->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(win->window, win->camera);
    if (!button_menu.sprite || !button_ext.sprite || !timed)
        return (84);
    while (win->state == in_death_menu && sfRenderWindow_isOpen(win->window))
        dead_loop(win, &button_menu, &button_ext);
    sfView_setCenter(win->camera, camera_center);
    time = time_to_float(timed);
    free_res(button_menu, button_ext, timed);
    win->is_reset = sfTrue;
    return (time);
}