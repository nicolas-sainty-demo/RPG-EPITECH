/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_quest
*/

#include "from_file.h"
#include "str.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int get_quest(char **info, entity_passive_t *passive, int i)
{
    if (my_strcmp_to_c(info[i], "quest_dialog=", '='))
        passive->quest.dialoge = get_string_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "quest_item=", '='))
        passive->quest.item_need = get_string_after_c(info[i], '=');
    if (my_strcmp_to_c(info[i], "xp_win=", '='))
        passive->quest.xp_win = get_the_int_after_c(info[i], '=');
}