/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** struct_projectile
*/

#ifndef STRUCT_PROJECTILE_H_
#define STRUCT_PROJECTILE_H_

#include <SFML/System/Vector2.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>

enum state_projectile_e
{
    no_shoot,
    shooted,
    arrived,
    reload
};

typedef struct projectile_s
{
    sfClock *clock;
    sfVector2f init_pos;
    sfVector2f final_pos;
    int speed_given;
    sfVector2f vector_speed;
    sfSprite *spt_projectile;
    sfTexture *text_projectile;
    enum state_projectile_e state;
    int radius;
} projectile_t;


#endif /* !STRUCT_PROJECTILE_H_ */
