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

void init_elem_player(player_t *player);

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
        if (my_strcmp_to_c(info[i], "damage", 'c'))
            player->damage = get_the_int_after_c(info[i], '=');
        if (my_strcmp_to_c(info[i], "position", '=')) {
            sfVector2i pos = get_the_vector_i_after_c(info[i], '=');
            sfSprite_setPosition(player->sprite, (sfVector2f){pos.x, pos.y});
        }
        if (my_strcmp_to_c(info[i], "projectile", '=')) {
            get_string_after_c(info[i], '=');
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

static void set_player_variable(player_t *player)
{
    player->animation_clock = sfClock_create();
    player->flip = sfFalse;
    player->anime = 0;
    player->speed = 500;
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
    init_elem_player(player);
    free (name_of_dir);
    closedir(folder);
    set_info(info, player);
    free_char_tab(info);
    set_player_variable(player);
    return (0);
}