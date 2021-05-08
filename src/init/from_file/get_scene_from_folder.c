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

int set_entyte_from_folader\
(entity_enemy_t **enemy, entity_passive_t **passive, const char *scene_name)
{
    if (set_enemy_from_foalders\
    (enemy, my_strcat(scene_name, "/entity/enemy/")) == 84)
        return (84);
    if (set_passive_from_foalder\
    (passive, my_strcat(scene_name, "/entity/passif/")) == 84)
        return (84);
    return (0);
}

static int fetch_information_from_folder\
(scene_t *scene, const char *scene_name, struct dirent *dirdir)
{
    if (my_strcmp(dirdir->d_name, "player"))
        get_player_from_file\
        (scene->player, my_strcat(scene_name, "/player"));
    if (my_strcmp(dirdir->d_name, "map"))
        get_map_from_file\
        (scene->map, my_strcat(scene_name, "/map"));
    if (my_strcmp(dirdir->d_name, "entity"))
        if (set_entyte_from_folader\
        (scene->enemy, scene->passive, scene_name) == 84)
            return (84);
    return (0);
}

static int extract_the_folder\
(DIR *folder, scene_t *scene, const char *scene_name)
{
    struct dirent *dirdir = NULL;

    set_defo_scene(scene, scene_name);
    dirdir = readdir(folder);
    while (dirdir != NULL) {
        if (dirdir->d_name[0] != '.') {
            if (fetch_information_from_folder(scene, scene_name, dirdir) == 84)
                return (84);
        }
        dirdir = readdir(folder);
    }
    return (0);
}

scene_t *get_scene_from_folder(const char *scene_name)
{
    scene_t *scene = malloc(sizeof(scene_t));
    DIR *folder;
    int return_ = 0;

    if (scene == NULL || scene_name == NULL)
        return (NULL);
    folder = opendir(scene_name);
    if (folder == NULL)
        return (NULL);
    return_ = extract_the_folder(folder, scene, scene_name);
    closedir(folder);
    if (return_ == 84)
        return (NULL);
    return (scene);
}