/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** set_passive_from_foalder
*/

#include "from_file.h"
#include "str.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int get_passif_from_info(char **info, entity_passive_t *passive);

int init_step_by_step(entity_passive_t **passive, char *name_of_dir, DIR *folder)
{
    char **info = NULL;
    struct dirent *dirdir = NULL;
    int return_ = 0;

    dirdir = readdir(folder);
    for (int i = 0; passive[i] != NULL && dirdir != NULL; i += 1) {
        while (dirdir->d_name[0] == '.')
            dirdir = readdir(folder);
        get_char_tab_from_file(&info, name_of_dir, dirdir->d_name, '\n');
        if (get_passif_from_info(info, passive[i]) == 84) {
            free_char_tab(info);
            return_ = 84;
            break;
        }
        free_char_tab(info);
        info = NULL;
        dirdir = readdir(folder);
    }
    return (return_);
}

int set_passive_from_foalder(entity_passive_t **passive, char *name_of_dir)
{
    DIR *folder;
    int return_ = 0;

    folder = opendir(name_of_dir);
    if (folder == NULL)
        return (84);
    return_ = init_step_by_step(passive, name_of_dir, folder);
    closedir(folder);
    free(name_of_dir);
    return (return_);
}