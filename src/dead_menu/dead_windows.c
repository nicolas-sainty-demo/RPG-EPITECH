/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** dead_windows
*/

#include "window_fonction.h"
#include "gameplay/dead_menu.h"
#include <stdio.h>

void init_dead_menu(dead_me *d_menu)
{
    d_menu->d_menu_texture = sfTexture_createFromFile
    ("res/dead_menu/rpg_over.png", NULL);
    d_menu->d_menu_sprite = sfSprite_create();
    sfSprite_setTexture(d_menu->d_menu_sprite, d_menu->d_menu_texture, sfTrue);
    d_menu->d_menu_te_reset = sfTexture_createFromFile
    ("res/dead_menu/reset_dead_menu.png", NULL);
    d_menu->d_menu_sp_reset = sfSprite_create();
    sfSprite_setTexture(d_menu->d_menu_sp_reset, d_menu->d_menu_te_reset, sfTrue);
}

void set_and_pos(the_window *windows, sfVector2f view)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    sfVector2f pos;
    pos.x = -960;
    pos.y = -555;
    sfVector2f pos_reset;
    pos_reset.x = -180;
    pos_reset.y = -100;
    sfSprite_setPosition(windows->d_menu->d_menu_sprite, pos);
    sfRenderWindow_drawSprite(windows->window, windows->d_menu->d_menu_sprite , NULL);
    sfSprite_setPosition(windows->d_menu->d_menu_sp_reset, pos_reset);
    sfRenderWindow_drawSprite(windows->window, windows->d_menu->d_menu_sp_reset, NULL);
    sfRenderWindow_display(windows->window);
}

void event_reset(the_window *windows)
{
    if (fct_delouis == 0) {
        windows->state = 0;
        windows->scene->player->hp = 150;
    }
}

int button_press(the_window *windows)
{
    sfVector2f pos_mouse_coords = { 0 };
    sfVector2i pos_mouse = { 0 };
    sfFloatRect rect_button = { 0 };
    sfVector2f pos_button = { 0 };
    pos_mouse = sfMouse_getPositionRenderWindow(windows->window);
    pos_mouse_coords = sfRenderWindow_mapPixelToCoords(windows->window\
    , pos_mouse, windows->camera);
    pos_button = sfSprite_getPosition(windows->d_menu->d_menu_sp_reset);
    rect_button = sfSprite_getGlobalBounds(windows->d_menu->d_menu_sp_reset);
}

float dead_menu(the_window *windows)
{
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);

    while (windows->state == 2 && sfRenderWindow_isOpen(windows->window)) {
        set_and_pos(windows, camera_center);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
            if (windows->event.type == sfEvtMouseButtonPressed)
                event_reset(windows);
    }
    sfView_setCenter(windows->camera, camera_center);
    float save = time_to_float(timed);
    return (save);
}