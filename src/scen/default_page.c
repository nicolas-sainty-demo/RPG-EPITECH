/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** default_page
*/

#include <stdbool.h>
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
#include "win_menu.h"
#include "free_res.h"

void gameplay_scene(the_window *windows);

float inventory_scene(the_window *windows);

float status_menus(the_window *windows);

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

void third_scene(the_window *windows)
{
    if (windows->state == in_status)
        status_menus(windows);
}

void victory_scene(the_window *windows)
{
    char *path_all[] = {"res/scene/debut"\
    , "res/scene/nivo_b", "res/scene/nivo_c"};

    if (windows->state == in_win) {
        windows->index++;
        if (windows->index > NB_SCENES - 1) {
            win_menu(windows);
            windows->index = 0;
            windows->state = in_menu;
        } else {
            windows->is_reset = sfTrue;
            reset_scene_struct(windows, windows->is_reset\
            , path_all[windows->index]);
            windows->state = in_game;
        }
    }
}

int default_page(the_window *windows)
{
    windows->state = in_menu;
    windows->usekey = sfFalse;
    windows->is_reset = false;
    windows->index = 0;
    windows->scene = get_scene_from_folder("res/scene/debut");
    if (!windows->scene)
        return (84);
    windows->scene->pos_items = NULL;
    while (sfRenderWindow_isOpen(windows->window)) {
        sfRenderWindow_clear(windows->window, sfBlack);
        speed_of_game((float)1/60);
        principal_scenes(windows);
        secondary_scenes(windows);
        victory_scene(windows);
        third_scene(windows);
        sfRenderWindow_display(windows->window);
    }
    reset_scene_struct(windows, windows->is_reset, "res/scene/debut");
    return (0);
}