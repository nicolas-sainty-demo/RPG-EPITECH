/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "map.h"
#include "projectile.h"

#include <stdlib.h>

static void draw(the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    draw_map(windows->window, windows->scene->map, 16);
    sfRenderWindow_drawSprite\
    (windows->window, windows->scene->player->sprite, NULL);
}

static void update(the_window *windows)
{
    draw(windows);
}

void default_page(the_window *windows)
{
    projectile_t proj1 = init_projectile("res/projectile/bullet.png", 20, 5);


    while (sfRenderWindow_isOpen(windows->window)) {
        speed_of_game((float)1/60);
        update(windows);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
            if ((windows->event.type = sfEvtMouseButtonPressed) &&\
             sfMouse_isButtonPressed(sfMouseLeft) && proj1.state != shooted) {
                sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(windows->window);
                if (proj1.state == no_shoot)  {
                    printf("in\n");
                    proj1.final_pos = (sfVector2f){pos_mouse.x, pos_mouse.y};
                    shoot_projectile(&proj1, (sfVector2f){500, 500}, proj1.final_pos);
                }
            }
        }
        update_projectile(&proj1);
        draw_projectile(windows->window, proj1);
        sfRenderWindow_display(windows->window);
    }

}