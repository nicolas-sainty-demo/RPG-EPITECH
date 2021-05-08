/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** show_healbar_ennemies
*/

#include "ennemies.h"

void show_healbar(the_window *windows, int const i)
{
    sfVector2f heal_min_max = (sfVector2f){windows->scene->enemy[i]->hp\
            , windows->scene->enemy[i]->hp_max};
    sfVector2f pos_ennemie = sfSprite_getPosition\
    (windows->scene->enemy[i]->sprite);
    sfFloatRect bnd_sprite = \
    sfSprite_getGlobalBounds(windows->scene->enemy[i]->sprite);
    sfVector2f size_bar_heal = (sfVector2f){bnd_sprite.width, SIZE_BAR_HEAL.y};
    pos_ennemie.y -= SIZE_BAR_HEAL.y;
    draw_heal_bar(size_bar_heal, heal_min_max, pos_ennemie, windows->window);
}