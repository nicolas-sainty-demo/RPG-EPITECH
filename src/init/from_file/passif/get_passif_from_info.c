/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_passif_from_info
*/

#include "from_file.h"
#include "str.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int get_primordial_variable_ent\
(char **info, entity_passive_t *passive, int i);

static void get_the_conversation(char **info, entity_passive_t *passive, int i)
{
    char *text = NULL;
    char *segond_info = NULL;

    if (my_strcmp_to_c(info[i], "speek=", '=')) {
        text = get_string_after_c(info[i], '=');
        if (my_reader(text, &segond_info) == 0)
            passive->conversation = str_to_a_tab(segond_info, '/');
    }
}

static void get_basic_variable(char **info, entity_passive_t *passive, int i)
{
    sfVector2i to_convert = {0};

    get_the_conversation(info, passive, i);
    if (my_strcmp_to_c(info[i], "position=", '=')) {
        to_convert = get_the_vector_i_after_c(info[i], '=');
        sfSprite_setPosition\
        (passive->sprite, (sfVector2f){to_convert.x, to_convert.y});
    }
    if (my_strcmp_to_c(info[i], "size=", '=')) {
        to_convert = get_the_vector_i_after_c(info[i], '=');
        sfSprite_setScale\
        (passive->sprite, (sfVector2f){to_convert.x, to_convert.y});
    }
}

int get_passif_from_info(char **info, entity_passive_t *passive)
{
    passive->quest.dialoge = NULL;
    passive->conversation = NULL;
    for (int i = 0; info[i] != NULL; i += 1) {
        passive->conversation = NULL;
        if (get_primordial_variable_ent(info, passive, i) == 84)
            return (84);
        get_basic_variable(info, passive, i);
        if (my_strcmp_to_c(info[i], "rec=", '='))
            sfSprite_setTextureRect\
            (passive->sprite, get_sf_int_rect_after_c(info[i], '='));
        get_quest(info, passive, i);
    }
    return (0);
}