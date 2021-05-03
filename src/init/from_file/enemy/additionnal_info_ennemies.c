/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** additionnal_info_ennemies
*/

#include "from_file.h"

void set_type_radius(entity_enemy_t *ennemie)
{
    int radius[] = {300, 200, 400};
    int cooldown[] = {4, 2, 10};

    for (int i = 0; i < 3; i++) {
        if (ennemie->type >= 0 && ennemie->type <= 2) {
            ennemie->radius = radius[ennemie->type];
            ennemie->coold = cooldown[ennemie->type];
        }
        else {
            ennemie->radius = radius[0];
            ennemie->coold = radius[0];
        }
        ennemie->state = passive;
    }
}