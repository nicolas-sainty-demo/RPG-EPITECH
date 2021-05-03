/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_projectile
*/

#include <SFML/Graphics/Texture.h>
#include <malloc.h>

#include "projectile.h"

void free_projectile(projectile_t **projectiles)
{
    int i = 0;

    while (projectiles[i]) {
        sfClock_destroy(projectiles[i]->clock);
        sfSprite_destroy(projectiles[i]->spt_projectile);
        sfTexture_destroy(projectiles[i]->text_projectile);
        free(projectiles[i]);
        i++;
    }
    free(projectiles);
}