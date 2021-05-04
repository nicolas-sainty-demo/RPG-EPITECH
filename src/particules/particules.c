/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** particules
*/

#include <stdlib.h>
#include <math.h>
#include "particules.h"

particules_t init_particl(unsigned int count, unsigned int time_to_live)
{
    particules_t particles;

    particles.m_particules = malloc(sizeof(*particles.m_particules) * count);
    particles.m_vertices = malloc(sizeof(sfVertex) * count);
    particles.clock = sfClock_create();
    if (!particles.m_particules || !particles.m_vertices || !particles.clock)
        return ((particules_t){0});
    for (unsigned int i = 0; i < count; i++) {
        particles.m_particules[i].lifetime = sfTime_Zero;
        particles.m_particules[i].velocity = (sfVector2f){0, 0};
        particles.m_vertices[i].position = (sfVector2f){0, 0};
        particles.m_vertices[i].texCoords = (sfVector2f){0, 0};
        particles.m_vertices[i].color = sfRed;
    }
    particles.time_to_live = time_to_live;
    particles.m_lifetime = sfSeconds(10);
    particles.m_emmiter.x = 0;
    particles.m_emmiter.y = 0;
    particles.nb_particules = count;
    return (particles);
}

void reset_particule(particules_t *particles, unsigned int index)
{
    float angle = ((rand() % 360) * 3.14) / 180;
    float speed = (rand() % 50) + 50;
    particles->m_particules[index].velocity = \
    (sfVector2f){cos(angle) * speed, sin(angle) * speed};
    particles->m_particules[index].lifetime = \
    sfMilliseconds(particles->time_to_live);
    particles->m_vertices[index].position = particles->m_emmiter;
}

void update_particules(sfTime elapsed, particules_t *particl, \
sfVector2f pos)
{
    float ratio = 0;
    particl->m_emmiter = pos;

    for (unsigned i = 0; i < particl->nb_particules; i++) {
        particl->m_particules[i].lifetime.microseconds -= elapsed.microseconds;
        if (particl->m_particules[i].lifetime.microseconds \
        <= sfTime_Zero.microseconds)
            reset_particule(particl, i);
        particl->m_vertices[i].position.x +=  \
        particl->m_particules[i].velocity.x * sfTime_asSeconds(elapsed);
        particl->m_vertices[i].position.y +=  \
        particl->m_particules[i].velocity.y * sfTime_asSeconds(elapsed);
        ratio = sfTime_asSeconds(particl->m_particules[i].lifetime) \
        / sfTime_asSeconds(particl->m_lifetime);
        particl->m_vertices[i].color.a = (sfUint8){ratio * 255};
    }
}

void free_particules(particules_t particl)
{
    free(particl.m_particules);
    free(particl.m_vertices);
    sfClock_destroy(particl.clock);
}