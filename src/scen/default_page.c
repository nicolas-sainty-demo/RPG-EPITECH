/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include "window_struc.h"
#include "window_fonction.h"

int check_if_collision_btw_square_without_rotation(sfSprite *const sprite_1\
, sfSprite *const sprite_2);

sfCircleShape *init_hitbox_circle(int const radius, sfSprite *sprite);

int check_if_collision_btw_circle_square(int const radius\
, sfSprite *const sprite_circle, sfSprite *const sprite_square);

static void draw(the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
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
        sfRenderWindow_display(windows->window);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
        }
    }
}