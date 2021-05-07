/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** fct_menu
*/

#include "window_struc.h"

void menu_play(void *ptr)
{
    the_window *window = ptr;

    window->state = in_game;
}

void menu_exit(void *ptr)
{
    the_window *window = ptr;

    sfRenderWindow_close(window->window);
}

void menu_settings(void *ptr)
{
    the_window *window = ptr;

    window->state = in_settings;
}