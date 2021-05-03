/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** event_projectile
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics/View.h>

#include "window_struc.h"
#include "projectile.h"

static void is_shoot(sfEvent event, projectile_t *proj,  the_window *windows\
, sfVector2f pos_player)
{
    sfVector2f pos_mouse_coords = { 0 };
    sfVector2i pos_mouse = { 0 };

    if ((event.type == sfEvtMouseButtonPressed) && \
        sfMouse_isButtonPressed(sfMouseLeft) && proj->state != shooted) {
        pos_mouse = sfMouse_getPositionRenderWindow(windows->window);
        pos_mouse_coords = sfRenderWindow_mapPixelToCoords(windows->window\
        , pos_mouse, windows->camera);
        if (proj->state == no_shoot)  {
            proj->final_pos = pos_mouse_coords;
            shoot_projectile(proj, pos_player, proj->final_pos);
        }
    }
}

void event_projectile(sfEvent event, projectile_t **proj, the_window *windows)
{
    static int what_projectile = 0;
    sfVector2f pos_player = { 0 };
    sfFloatRect bound_player = { 0 };

    for (int i = 0; proj[i] != NULL; i++) {
        if (proj[i]->state == no_shoot) {
            what_projectile = i;
            break;
        }
    }
    pos_player = sfSprite_getPosition(windows->scene->player->sprite);
    bound_player = sfSprite_getGlobalBounds(windows->scene->player->sprite);
    pos_player.x += bound_player.width/2;
    pos_player.y += bound_player.height/2;
    is_shoot(event, proj[what_projectile], windows, pos_player);
}