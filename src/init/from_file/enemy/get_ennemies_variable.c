/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_ennemies_variable
*/

#include "from_file.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void get_secondary_variable(char **info, entity_enemy_t *enemy, int i)
{
    if (my_strcmp_to_c(info[i], "damage=", '='))
        enemy->damage = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "type=", '='))
        enemy->type = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "animeFrame=", '='))
        enemy->anime = get_the_int_after_c(info[i], '=');
}

int get_primordial_variable(char **info, entity_enemy_t *enemy, int i)
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
    get_secondary_variable(info, enemy, i);
    return (0);
}

int get_basic_variable(char **info, entity_enemy_t *enemy, int i)
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