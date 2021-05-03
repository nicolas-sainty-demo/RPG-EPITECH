/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** event_projectile
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics/View.h>

#include "projectile.h"

static void is_shoot(sfEvent event, sfRenderWindow *window\
, projectile_t *proj,  sfVector2f pos_player)
{
    if ((event.type == sfEvtMouseButtonPressed) && \
        sfMouse_isButtonPressed(sfMouseLeft) && proj->state != shooted) {
        sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(window);
        if (proj->state == no_shoot)  {
            proj->final_pos = (sfVector2f){pos_mouse.x, pos_mouse.y};
            shoot_projectile(proj, pos_player, proj->final_pos);
        }
    }
}

void event_projectile(sfEvent event, sfRenderWindow *window\
, projectile_t **proj, sfVector2f pos_player)
{
    static int what_projectile = 0;

    for (int i = 0; proj[i] != NULL; i++) {
        if (proj[i]->state == no_shoot) {
            what_projectile = i;
            break;
        }
    }
    is_shoot(event, window, proj[what_projectile], pos_player);
}