/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_map_from_file
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include <dirent.h>
#include <sys/types.h>
#include "from_file.h"

static void set_info(char **info, map_t *map)
{
    for (int i = 0; info[i] != NULL; i += 1) {
        if (my_strcmp_to_c(info[i], "sprite_sol", '='))
            map->sprite_sol = get_sprite_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "sprite_sol_rec", '=')) {
            sfSprite_setTextureRect\
            (map->sprite_sol, get_sf_int_rect_after_c(info[i], '='));
        }
        if (my_strcmp_to_c(info[i], "size", '=')) {
            sfVector2i vector = get_the_vector_i_after_c(info[i], '=');
            sfSprite_setScale(map->sprite_sol, (sfVector2f)\
            {vector.x / 100, vector.y / 100});
        }
    }
    free(info);
}

static void extract_the_folder_map\
(DIR *folder, map_t *map, const char *name_of_dir)
{
    struct dirent *dirdir = NULL;
    char **info = NULL;

    dirdir = readdir(folder);
    while (dirdir != NULL) {
        if (dirdir->d_name[0] != '.') {
            if (my_strcmp(dirdir->d_name, "sol"))
                get_char_tab_from_file(&map->sol, name_of_dir, "/sol", '\n');
            if (my_strcmp(dirdir->d_name, "info"))
                get_char_tab_from_file(&info, name_of_dir, "/info", '\n');
        }
        dirdir = readdir(folder);
    }
    set_info(info, map);
}

int get_map_from_file(map_t *map, char *name_of_dir)
{
    DIR *folder = NULL;
    char **info = NULL;

    if (name_of_dir == NULL)
        return (84);
    folder = opendir(name_of_dir);
    if (folder == NULL) {
        return (84);
    }
    extract_the_folder_map(folder, map, name_of_dir);
    free (name_of_dir);
    closedir(folder);
    free_char_tab(info);
    return (0);
}