/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_scene_from_folder
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include "from_file.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

map_t *creat_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->layer_a = NULL;
    map->layer_b = NULL;
    map->layer_c = NULL;
    map->map_layer_a = NULL;
    map->map_layer_b = NULL;
    map->map_layer_c = NULL;
    map->tils_colition = NULL;
    return (map);
}

static void extract_the_folder\
(DIR *folder, scene_t *scene, const char *scene_name)
{
    struct dirent *dirdir = NULL;
    scene->player = malloc(sizeof(player_t));
    scene->map = creat_map();

    dirdir = readdir(folder);
    while (dirdir != NULL) {
        if (dirdir->d_name[0] != '.') {
            if (my_strcmp(dirdir->d_name, "player"))
                get_player_from_file\
                (scene->player, my_strcat(scene_name, "/player"));
            if (my_strcmp(dirdir->d_name, "map"))
                get_map_from_file\
                (scene->map, my_strcat(scene_name, "/map"));
        }
        dirdir = readdir(folder);
    }
}

scene_t *get_scene_from_folder(const char *scene_name)
{
    scene_t *scene = malloc(sizeof(scene_t));
    DIR *folder;

    if (scene == NULL || scene_name == NULL)
        return (NULL);
    folder = opendir(scene_name);
    if (folder == NULL) {
        return (NULL);
    }
    extract_the_folder(folder, scene, scene_name);
    closedir(folder);
    return (scene);
}