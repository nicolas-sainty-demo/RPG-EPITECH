/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** fct_setting
*/

#include "window_struc.h"

void go_back_to_menu(void *ptr)
{
    the_window *window = ptr;

    window->state = in_menu;
}

void up_song(void *ptr)
{
    the_window *window = ptr;

    if (window->volume <= window->volume_min_max.y) {
        window->volume += 10;
    }
    sfMusic_setVolume(window->music , (float)window->volume);
}

void down_song(void *ptr)
{
    the_window *window = ptr;

    if (window->volume >= window->volume_min_max.x) {
        window->volume -= 10;
    }
    sfMusic_setVolume(window->music , (float)window->volume);
}