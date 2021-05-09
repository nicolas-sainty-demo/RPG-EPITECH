/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_projectile
*/

#include <SFML/Graphics/Texture.h>
#include <malloc.h>

#include "particules.h"
#include "projectile.h"

void free_projectile(projectile_t *projectiles)
{
    if (projectiles->particl.m_vertices)
        free_particules(projectiles->particl);
    sfClock_destroy(projectiles->clock);
    sfSprite_destroy(projectiles->spt_projectile);
    sfTexture_destroy(projectiles->text_projectile);
    free(projectiles);
}

void free_tab_projectile(projectile_t **projectiles)
{
    int i = 0;

    while (projectiles[i]) {
        free_projectile(projectiles[i]);
        i++;
    }
    free(projectiles);
}