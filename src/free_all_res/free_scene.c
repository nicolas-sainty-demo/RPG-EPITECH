/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_scene
*/

#include "free_res.h"
#include "from_file.h"

void reset_scene_struct(the_window *windows, bool is_reset, char *path)
{
    windows->quest_finiche = 0;
    windows->state = in_menu;
    windows->usekey = sfFalse;
    windows->is_reset = false;
    free_tab_ennemies(windows->scene->enemy);
    free_tab_entity_passive(windows->scene->passive);
    free_map(windows->scene->map);
    free_player(windows->scene->player);
    free_items_on_ground(&windows->scene->pos_items);
    free(windows->scene);
    windows->scene = NULL;
    if (is_reset == true) {
        windows->scene = get_scene_from_folder(path);
        windows->scene->pos_items = NULL;
    }
}