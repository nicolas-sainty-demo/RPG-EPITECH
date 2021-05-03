/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include <stdbool.h>
#include "window_struc.h"
#include "window_fonction.h"
#include "map.h"
#include "collision.h"
#include "move.h"
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/View.h>
#include "projectile.h"
#include <stdlib.h>
#include "draw.h"
#include "from_file.h"
#include "gameplay/inventory.h"
#include "ennemies.h"
#include "dead_menu.h"
#include "pause.h"
#include "main_menu.h"
#include "text.h"

void gameplay_scene(the_window *windows);

float speek\
(the_window *windows, char **conversation, entity_passive_t *passif);

float inventory_scene(the_window *windows);

void principal_scenes(the_window *windows)
{
    if (windows->state == in_menu)
        main_menu(windows);
    if (windows->state == in_settings)
        settings_menu(windows);
    if (windows->state == in_game)
        gameplay_scene(windows);
}

void secondary_scenes(the_window *windows)
{
    if (windows->state == in_inventory)
        inventory_scene(windows);
    if (windows->state == in_death_menu)
        dead_menu(windows);
    if (windows->state == in_pause)
        pause_menu(windows);
}

void default_page(the_window *windows)
{
    windows->state = in_menu;
    windows->usekey = sfFalse;
    windows->scene = get_scene_from_folder("res/scene/debut");
    windows->scene->pos_items = NULL;
    while (sfRenderWindow_isOpen(windows->window)) {
        sfRenderWindow_clear(windows->window, sfBlack);
        speed_of_game((float)1/60);
        principal_scenes(windows);
        secondary_scenes(windows);
        sfRenderWindow_display(windows->window);
    }
    free_projectile(windows->scene->player->proj);
}