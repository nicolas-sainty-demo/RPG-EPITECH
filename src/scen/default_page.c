/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "collision.h"

#include <stdlib.h>

static void draw(the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    sfRenderWindow_display(windows->window);
}

static void update(the_window *windows)
{
    draw(windows);
}

void default_page(the_window *windows)
{
    while (sfRenderWindow_isOpen(windows->window)) {
        speed_of_game((float)1/60);
        update(windows);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
        }
    }

}