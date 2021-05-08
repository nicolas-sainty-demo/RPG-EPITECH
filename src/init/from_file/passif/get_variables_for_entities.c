/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_variables_for_entities
*/

#include "from_file.h"
#include "str.h"
#include <stdlib.h>
#include <stdio.h>

static void get_secondary_variable(char **info\
, entity_passive_t *passive, int i)
{
    if (my_strcmp_to_c(info[i], "hp=", '='))
        passive->hp = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "damage=", '='))
        passive->damage = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "type=", '='))
        passive->type = get_the_int_after_c(info[i], '=');
}

static void get_primary_variable_ent\
(char **info, entity_passive_t *passive, int i)
{
    if (my_strcmp_to_c(info[i], "animeFrame=", '='))
        passive->anime = get_the_int_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "speed=", '='))
        passive->speed = get_the_int_after_c(info[i], '=');
}

int get_primordial_variable_ent\
(char **info, entity_passive_t *passive, int i)
{
    if (my_strcmp_to_c(info[i], "sprite=", '=')) {
        passive->sprite = get_sprite_after_c(info[i], '=');
        if (passive->sprite == NULL)
            return (84);
    }
    get_primary_variable_ent(info, passive, i);
    get_secondary_variable(info, passive, i);
    return (0);
}