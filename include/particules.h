/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** particules
*/

#ifndef PARTICULES_H_
#define PARTICULES_H_

#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>

typedef struct info_particule_s
{
    sfVector2f velocity;
    sfTime lifetime;
} info_particule_t;

typedef struct particules_s
{
    info_particule_t *m_particules;
    unsigned int nb_particules;
    sfVertex *m_vertices;
    sfTime m_lifetime;
    int time_to_live;
    sfVector2f m_emmiter;
    sfClock *clock;
} particules_t;

particules_t init_particl(unsigned int count, unsigned int time_to_live\
, sfColor color);
void reset_particule(particules_t *particles, unsigned int index\
, sfVector2f min_max);
void update_particules(sfTime elapsed, particules_t *particl, \
sfVector2f pos, sfVector2f min_max);
void update_particules_player(sfTime elapsed, particules_t *particl, \
sfVector2f pos, sfVector2f min_max);
void reset_particule_player(particules_t *particles, unsigned int index\
, sfVector2f min_max);
void free_particules(particules_t particl);

#endif /* !PARTICULES_H_ */