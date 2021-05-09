/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_particules
*/

#include <stdlib.h>
#include <math.h>
#include "window_struc.h"
#include "particules.h"

void update_particules_player(sfTime elapsed, particules_t *particl, \
sfVector2f pos, sfVector2f min_max)
{
    float ratio = 0;
    particl->m_emmiter = pos;

    for (unsigned i = 0; i < particl->nb_particules; i++) {
        particl->m_particules[i].lifetime.microseconds -= elapsed.microseconds;
        if (particl->m_particules[i].lifetime.microseconds \
        <= sfTime_Zero.microseconds)
            reset_particule_player(particl, i, min_max);
        particl->m_vertices[i].position.x +=  \
        particl->m_particules[i].velocity.x * sfTime_asSeconds(elapsed);
        particl->m_vertices[i].position.y +=  \
        particl->m_particules[i].velocity.y * sfTime_asSeconds(elapsed);
        ratio = sfTime_asSeconds(particl->m_particules[i].lifetime) \
        / sfTime_asSeconds(particl->m_lifetime);
        particl->m_vertices[i].color.a = (sfUint8){ratio * 255};
    }
}

void update_the_particules(projectile_t **proj)
{
    sfTime elapsed;
    int i = 0;
    particules_t particl;

    while (proj[i]) {
        particl = proj[i]->particl;
        elapsed = sfClock_restart(proj[i]->particl.clock);
        if (proj[i]->state == reload) {
            update_particules\
            (elapsed, &particl, proj[i]->init_pos, PARTICl_RAND);
        }
        i++;
    }
}

void update_particules_for_player(player_t *player)
{
    sfVector2f pos = sfSprite_getPosition(player->sprite);
    sfFloatRect bound_p = sfSprite_getGlobalBounds(player->sprite);
    sfTime elapsed = sfClock_restart(player->particl.clock);
    static int is_reset = 0;

    pos.x += bound_p.width/2;
    pos.y += bound_p.height;
    if (player->anime != player_stay) {
        update_particules_player(elapsed, &player->particl, pos, PARTICl_RAND);
        is_reset = 0;
    }
    else if (player->anime == player_stay && is_reset == 0) {
        is_reset = 1;
        for (unsigned int i = 0; i < player->particl.nb_particules; i++) {
            reset_particule_player(&player->particl, i, PARTICl_RAND);
        }
    }
}

void update_particules(sfTime elapsed, particules_t *particl, \
sfVector2f pos, sfVector2f min_max)
{
    float ratio = 0;
    particl->m_emmiter = pos;

    for (unsigned i = 0; i < particl->nb_particules; i++) {
        particl->m_particules[i].lifetime.microseconds -= elapsed.microseconds;
        if (particl->m_particules[i].lifetime.microseconds \
        <= sfTime_Zero.microseconds)
            reset_particule(particl, i, min_max);
        particl->m_vertices[i].position.x +=  \
        particl->m_particules[i].velocity.x * sfTime_asSeconds(elapsed);
        particl->m_vertices[i].position.y +=  \
        particl->m_particules[i].velocity.y * sfTime_asSeconds(elapsed);
        ratio = sfTime_asSeconds(particl->m_particules[i].lifetime) \
        / sfTime_asSeconds(particl->m_lifetime);
        particl->m_vertices[i].color.a = (sfUint8){ratio * 255};
    }
}