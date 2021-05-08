/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** draw_game
*/

#include "projectile.h"
#include "window_fonction.h"

void draw_heal_bar_player(player_t *player, the_window *window)
{
    sfVector2f heal_min_max = {player->hp, player->hp_max};
    sfVector2i pos = {30, 30};

    sfVector2f pos_2 = \
    sfRenderWindow_mapPixelToCoords(window->window, pos, window->camera);
    draw_heal_bar((sfVector2f){200, 50}, heal_min_max, pos_2, window->window);
}

void draw_player(the_window *windows)
{
    player_t *player = windows->scene->player;

    draw_all_projectiles(windows->window, player->proj);
    for (int i = 0; player->proj[i]; i++) {
        sfRenderWindow_drawPrimitives(windows->window\
        , player->proj[i]->particl.m_vertices,\
            player->proj[i]->particl.nb_particules, sfPoints, NULL);
    }
    sfRenderWindow_drawPrimitives(windows->window, \
    player->particl.m_vertices, player->particl.nb_particules, sfPoints, NULL);
    draw_heal_bar_player(player, windows);
}