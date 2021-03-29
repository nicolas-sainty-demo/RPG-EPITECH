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

void set_info(char **info, map_t *map);

void get_layer(struct dirent *dirdir, const char *name_of_dir, map_t *map)
{
    if (my_strcmp(dirdir->d_name, "layer_a"))
        get_char_tab_from_file\
        (&map->map_layer_a, name_of_dir, "/layer_a", '\n');
    if (my_strcmp(dirdir->d_name, "layer_b"))
        get_char_tab_from_file\
        (&map->map_layer_b, name_of_dir, "/layer_b", '\n');
    if (my_strcmp(dirdir->d_name, "layer_c"))
        get_char_tab_from_file\
        (&map->map_layer_c, name_of_dir, "/layer_c", '\n');
}

static void extract_the_folder_map\
(DIR *folder, map_t *map, const char *name_of_dir)
{
    struct dirent *dirdir = NULL;
    char **info = NULL;

    dirdir = readdir(folder);
    while (dirdir != NULL) {
        if (dirdir->d_name[0] != '.') {
            get_layer(dirdir, name_of_dir, map);
            if (my_strcmp(dirdir->d_name, "info"))
                get_char_tab_from_file(&info, name_of_dir, "/info", '\n');
        }
        dirdir = readdir(folder);
    }
    set_info(info, map);
}

char **get_tils_coliton(char **layer)
{
    char **coliton = malloc(sizeof(char *) * (get_tab_max(layer) + 1));
    int x = 0;
    int y = 0;

    while (layer[y] != NULL) {
        coliton[y] = malloc(sizeof(char) * (my_strlen(layer[y]) + 1));
        while (layer[y][x] != '\0') {
            if (layer[y][x] == '0')
                coliton[y][x] = 1;
            else
                coliton[y][x] = -1;
            x += 1;
        }
        coliton[y++][x] = '\0';
        x = 0;
    }
    coliton[y] = NULL;
    return (coliton);
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
    map->tils_colition = get_tils_coliton(map->map_layer_b);
    return (0);
}