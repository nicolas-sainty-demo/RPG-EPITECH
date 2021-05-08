/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** pause_fct
*/

#include "window_struc.h"
#include "pause.h"

void go_menu(void *ptr)
{
    the_window *windows = ptr;

    windows->state = in_menu;
}

void go_exit(void *ptr)
{
    the_window *windows = ptr;

    sfRenderWindow_close(windows->window);
}

void go_resume(void *ptr)
{
    the_window *windows = ptr;

    windows->state = in_game;
}

void free_res_pause(struct pause_s pause, sfClock *timed)
{
    sfTexture_destroy(pause.texture);
    sfSprite_destroy(pause.sprite);
    sfClock_destroy(timed);
}