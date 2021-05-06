/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** info_about_projectile
*/

#include "projectile.h"

float calc_distance(const float p1, const float p2);

sfVector2f calc_speed_vector(const int speed, const sfVector2f depart_pos\
, const sfVector2f arrival_pos);

void shoot_projectile(projectile_t *projectile, \
sfVector2f init_pos, sfVector2f final_pos)
{
    projectile->init_pos = init_pos;
    projectile->final_pos = final_pos;
    projectile->vector_speed = \
    calc_speed_vector(projectile->speed_given, init_pos, final_pos);
    projectile->state = shooted;
    sfSprite_setPosition(projectile->spt_projectile, POS_INITIAL_PROJ);
}

void move_projectile(projectile_t *projectile, sfFloatRect bounds_spt)
{
    projectile->init_pos.x += projectile->vector_speed.x;
    projectile->init_pos.y += projectile->vector_speed.y;
    sfSprite_setPosition(projectile->spt_projectile\
    , (sfVector2f){projectile->init_pos.x - (bounds_spt.width/2)\
    , projectile->init_pos.y - (bounds_spt.height/2)});
}

void is_projectile_arrived(projectile_t *prjt, sfFloatRect bounds)
{
    if (prjt->init_pos.x > prjt->final_pos.x - (bounds.width/4)\
    && prjt->init_pos.y > prjt->final_pos.y - (bounds.height/4)
    && prjt->init_pos.x < prjt->final_pos.x + (bounds.width/4)\
    && prjt->init_pos.y < prjt->final_pos.y + (bounds.height/4)) {
        prjt->state = arrived;
    }
}

void reload_ammo(projectile_t *proj)
{
    int time = sfTime_asSeconds(sfClock_getElapsedTime(proj->clock));

    if (proj->state == arrived) {
        sfClock_restart(proj->clock);
        proj->state = reload;
    } else if (proj->state == reload && time >= proj->reload_time) {
        proj->state = no_shoot;
    }
}
