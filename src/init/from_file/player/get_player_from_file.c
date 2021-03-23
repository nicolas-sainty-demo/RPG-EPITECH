/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_player_from_file
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include <dirent.h>
#include <sys/types.h>
#include "from_file.h"

static void set_info(char **info, player_t *player)
{
    for (int i = 0; info[i] != NULL; i += 1) {
        if (my_strcmp_to_c(info[i], "inventaire", '='))
            player->inventaire = get_string_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "hp", '='))
            player->hp = get_the_int_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "anime", '='))
            player->anime = (char)get_the_int_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "sprite", '='))
            player->sprite = get_sprite_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "sprite_rec", '=')) {
            sfSprite_setTextureRect\
            (player->sprite, get_sf_int_rect_after_c(info[i], '='));
        }
    }
}

static void extract_the_folder_player\
(DIR *folder, char ***info, const char *name_of_dir)
{
    struct dirent *dirdir = NULL;
    char *buffer = NULL;

    dirdir = readdir(folder);
    while (dirdir != NULL) {
        if (dirdir->d_name[0] != '.') {
            if (my_strcmp(dirdir->d_name, "info")) {
                get_char_from_file\
                (&buffer, name_of_dir, "/info");
            }
        }
        dirdir = readdir(folder);
    }
    *info = str_to_a_tab(buffer, '\n');
    free(buffer);
}

int get_player_from_file(player_t *player, char *name_of_dir)
{
    DIR *folder = NULL;
    char **info = NULL;

    if (name_of_dir == NULL)
        return (84);
    folder = opendir(name_of_dir);
    if (folder == NULL) {
        return (84);
    }
    extract_the_folder_player(folder, &info, name_of_dir);
    free (name_of_dir);
    closedir(folder);
    set_info(info, player);
    free_char_tab(info);
    return (0);
}