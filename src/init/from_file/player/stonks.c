/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** stonks
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include <dirent.h>
#include <sys/types.h>
#include "from_file.h"

static void get_primary_informations(char *info, player_t *player)
{
    if (my_strcmp_to_c(info, "anime", '='))
        player->anime = (char)get_the_int_after_c(info, '=');
    if (my_strcmp_to_c(info, "sprite", '='))
        player->sprite = get_sprite_after_c(info, '=');
    if (my_strcmp_to_c(info, "sprite_rec", '='))
        sfSprite_setTextureRect\
        (player->sprite, get_sf_int_rect_after_c(info, '='));
}

static void get_secondary_informations(char *info, player_t *player)
{
    if (my_strcmp_to_c(info, "damage", '='))
        player->damage = get_the_int_after_c(info, '=');
    if (my_strcmp_to_c(info, "position", '=')) {
        sfVector2i pos = get_the_vector_i_after_c(info, '=');
        sfSprite_setPosition(player->sprite, (sfVector2f){pos.x, pos.y});
    }
    if (my_strcmp_to_c(info, "projectile", '='))
        get_string_after_c(info, '=');
}

void stonks(char *info, player_t *player)
{
    if (my_strcmp_to_c(info, "inventaire", '='))
        player->inventaire = get_string_after_c(info, '=');
    if (my_strcmp_to_c(info, "hp", '='))
        player->hp = get_the_int_after_c(info, '=');
    get_primary_informations(info, player);
    get_secondary_informations(info, player);
}