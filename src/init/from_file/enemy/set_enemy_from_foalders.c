/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** set_enemy_from_foalders
*/

#include "from_file.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void add_additionnal_info(entity_enemy_t *ennemie);

static int get_primordial_variable(char **info, entity_enemy_t *enemy, int i)
{
    if (my_strcmp_to_c(info[i], "sprite=", '=')) {
        enemy->sprite = get_sprite_after_c(info[i], '=');
        if (enemy->sprite == NULL)
            return (84);
    }
    if (my_strcmp_to_c(info[i], "speed=", '='))
        enemy->speed = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "hp=", '=')) {
        enemy->hp = get_the_int_after_c(info[i], '=');
        enemy->hp_max =enemy-> hp;
    }
    if (my_strcmp_to_c(info[i], "damage=", '='))
        enemy->damage = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "type=", '='))
        enemy->type = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "animeFrame=", '='))
        enemy->anime = get_the_int_after_c(info[i], '=');
    return (0);
}

static int get_basic_variable(char **info, entity_enemy_t *enemy, int i)
{
    sfVector2i to_convert = {0};

    if (my_strcmp_to_c(info[i], "position=", '=')) {
        to_convert = get_the_vector_i_after_c(info[i], '=');
        enemy->current_pos = (sfVector2f){to_convert.x, to_convert.y};
        sfSprite_setPosition\
        (enemy->sprite, enemy->current_pos);
    }
    if (my_strcmp_to_c(info[i], "rec=", '='))
        sfSprite_setTextureRect\
        (enemy->sprite, get_sf_int_rect_after_c(info[i], '='));
    if (my_strcmp_to_c(info[i], "size=", '=')) {
        to_convert = get_the_vector_i_after_c(info[i], '=');
        sfSprite_setScale\
        (enemy->sprite, (sfVector2f){to_convert.x, to_convert.y});
    }
    return (0);
}

int get_enemy_from_info(char **info, entity_enemy_t *enemy)
{
    for (int i = 0; info[i] != NULL; i += 1) {
        if (get_primordial_variable(info, enemy, i) == 84)
            return (84);
        get_basic_variable(info, enemy, i);
    }
    return (0);
}

int get_an_enemy_from_file\
(struct dirent **dirdir, DIR *folder, char *name_of_dir, entity_enemy_t *enemy)
{
    char **info = NULL;

    while ((*dirdir)->d_name[0] == '.')
            (*dirdir) = readdir(folder);
        get_char_tab_from_file(&info, name_of_dir, (*dirdir)->d_name, '\n');
        if (info == NULL) {
            write(2, "info is NULL", 12);
            return (84);
        }
        if (get_enemy_from_info(info, enemy) == 84)
            return (84);
        free_char_tab(info);
        info = NULL;
        (*dirdir) = readdir(folder);
    return (0);
}

int set_enemy_from_foalders(entity_enemy_t **enemy, char *name_of_dir)
{
    DIR *folder;
    struct dirent *dirdir = NULL;
    int return_v = 0;

    folder = opendir(name_of_dir);
    if (folder == NULL)
        return (84);
    dirdir = readdir(folder);
    for (int i = 0; enemy[i] != NULL && dirdir != NULL; i += 1) {
        return_v = get_an_enemy_from_file\
        (&dirdir, folder, name_of_dir, enemy[i]);
        if (return_v == 84)
            break;
        add_additionnal_info(enemy[i]);
    }
    closedir(folder);
    free(name_of_dir);
    return (return_v);
}