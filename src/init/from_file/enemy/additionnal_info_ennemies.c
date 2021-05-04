/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** additionnal_info_ennemies
*/

#include "projectile.h"
#include "from_file.h"

void add_proj(entity_enemy_t *ennemie)
{
    if (ennemie->type == 1) {
        ennemie->proj = init_projectile(PATH_PROJ, RADIUS_PROJ, SPEED_PROJ);
    }
}

void add_additionnal_info(entity_enemy_t *ennemie)
{
    int area_vision[] = {300, 500, 400};
    int area_shoot[] = {0, 300, 0};
    int cooldown[] = {4, 0, 10};

    for (int i = 0; i < 3; i++) {
        if (ennemie->type >= 0 && ennemie->type <= 2) {
            ennemie->area_vision = area_vision[ennemie->type];
            ennemie->area_shoot = area_shoot[ennemie->type];
            ennemie->coold = cooldown[ennemie->type];
        }
        else {
            ennemie->area_vision = area_vision[0];
            ennemie->coold = area_vision[0];
            ennemie->area_shoot = area_shoot[ennemie->type];
        }
        ennemie->state = passive;
    }
    add_proj(ennemie);
}