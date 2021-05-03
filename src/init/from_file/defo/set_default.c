/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** set_default
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include "from_file.h"
#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>

map_t *creat_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    map->layer_a = NULL;
    map->layer_b = NULL;
    map->layer_c = NULL;
    map->map_layer_a = NULL;
    map->map_layer_b = NULL;
    map->map_layer_c = NULL;
    map->tils_colition = NULL;
    return (map);
}

void set_enemy_default(entity_enemy_t **enemy, int nbr_of_enemy)
{
    enemy[nbr_of_enemy] = NULL;
    for (int i = 0; i < nbr_of_enemy; i += 1) {
        enemy[i] = malloc(sizeof(entity_enemy_t));
        if (!enemy[i])
            return;
        enemy[i]->delay_attack = sfClock_create();
        enemy[i]->animation_clock = sfClock_create();
        enemy[i]->flip = 1;
        enemy[i]->attack = ready;
        enemy[i]->anime = 1;
        enemy[i]->damage = 1;
        enemy[i]->hp = 1;
        enemy[i]->speed = 1;
        enemy[i]->type = 0;
        enemy[i]->sprite = NULL;
    }
}

void set_passif_default(entity_passive_t **passiff, int nbr_of_passiff)
{
    passiff[nbr_of_passiff] = NULL;
    for (int i = 0; i < nbr_of_passiff; i += 1) {
        passiff[i] = malloc(sizeof(entity_passive_t));
        passiff[i]->animation_clock = sfClock_create();
        passiff[i]->flip = 1;
        passiff[i]->anime = 1;
        passiff[i]->damage = 1;
        passiff[i]->hp = 1;
        passiff[i]->speed = 1;
        passiff[i]->type = 0;
        passiff[i]->sprite = NULL;
    }
}

int set_defo_scene(scene_t *scene, const char *scene_name)
{
    char *file_enemy = my_strcat(scene_name, "/entity/enemy");
    char *file_passif = my_strcat(scene_name, "/entity/passif");
    int nbr_of_enemy = 0;
    int nbr_of_passif = 0;

    if (file_enemy == NULL || file_passif == NULL)
        return (84);
    nbr_of_enemy = get_nbr_of_fil_in_folder(file_enemy);
    nbr_of_passif = get_nbr_of_fil_in_folder(file_passif);
    free(file_enemy);
    scene->player = malloc(sizeof(player_t));
    scene->map = creat_map();
    scene->enemy = malloc(sizeof(entity_enemy_t *) * (nbr_of_enemy + 1));
    scene->passive = malloc(sizeof(entity_passive_t *) * (nbr_of_passif + 1));
    set_enemy_default(scene->enemy, nbr_of_enemy);
    set_passif_default(scene->passive, nbr_of_passif);
    return (0);
}