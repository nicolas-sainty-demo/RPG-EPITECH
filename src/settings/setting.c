/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** menu
*/

#include "window_fonction.h"
#include "struct_menu.h"
#include <stdio.h>
#include "button.h"

static void set_and_pos(the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    sfVector2f pos = {-960, -555};

    sfSprite_setPosition(windows->settings.sprites, pos);
    sfRenderWindow_drawSprite(windows->window, \
    windows->settings.sprites , NULL);
}

static void is_click(the_window *windows)
{
    if (windows->event.type == sfEvtMouseButtonPressed)
        windows->click = sfTrue;
    else
        windows->click = sfFalse;
}

void settings_loop(the_window *windows, main_menu_t *settings)
{
    update_tab_button(windows, settings->button, settings->nb_button);
    set_and_pos(windows);
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        is_click(windows);
        button_tab_event(windows, settings->button, settings->nb_button);
    }
    button_tab_draw(windows, settings->button, settings->nb_button);
    sfRenderWindow_display(windows->window);
}

float settings_menu(the_window *windows)
{
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    windows->click = sfFalse;

    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);
    while (windows->state == in_settings \
    && sfRenderWindow_isOpen(windows->window))
        settings_loop(windows, &windows->settings);
    sfView_setCenter(windows->camera, camera_center);
    return (time_to_float(timed));
}