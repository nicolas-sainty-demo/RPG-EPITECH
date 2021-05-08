/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** particules
*/

#include <stdlib.h>
#include <math.h>
#include "particules.h"


void update_particules(sfTime elapsed, particules_t *particl, \
sfVector2f pos, sfVector2f min_max);

void update_particules_player(sfTime elapsed, particules_t *particl, \
sfVector2f pos, sfVector2f min_max);

int my_rand(int min, int max)
{
    return ((rand() % (max - min)) + min);
}

particules_t init_particl(unsigned int count, unsigned int time_to_live\
, sfColor color)
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
        particles.m_vertices[i].color = color;
    }
    particles.time_to_live = time_to_live;
    particles.m_lifetime = sfSeconds(10);
    particles.m_emmiter.x = 0;
    particles.m_emmiter.y = 0;
    particles.nb_particules = count;
    return (particles);
}

void reset_particule(particules_t *particles, unsigned int index\
, sfVector2f min_max)
{
    float angle = ((my_rand(min_max.x, min_max.y)) * 3.14) / 180;
    float speed = (rand() % 50) + 50;
    particles->m_particules[index].velocity = \
    (sfVector2f){cos(angle) * speed, sin(angle) * speed};
    particles->m_particules[index].lifetime = \
    sfMilliseconds(particles->time_to_live);
    particles->m_vertices[index].position = particles->m_emmiter;
}

void reset_particule_player(particules_t *particles, unsigned int index\
, sfVector2f min_max)
{
    float angle = ((my_rand(min_max.x, min_max.y)) * 3.14) / 180;
    float speed = (rand() % 50) + 50;
    particles->m_particules[index].velocity = \
    (sfVector2f){cos(angle) * speed, sin(angle) * speed};
    particles->m_particules[index].lifetime = \
    sfMilliseconds((rand() % particles->time_to_live) + 1000);
    particles->m_vertices[index].position = particles->m_emmiter;
}

void free_particules(particules_t particl)
{
    free(particl.m_particules);
    free(particl.m_vertices);
    sfClock_destroy(particl.clock);
}