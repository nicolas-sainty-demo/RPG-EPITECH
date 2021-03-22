/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision
*/

#ifndef COLLISION_H_
#define COLLISION_H_

#include <SFML/Graphics/Sprite.h>

int is_collision_square_without_rotation(sfRectangleShape *const sqr_1\
, sfRectangleShape *const sqr_2);

int is_collision_circle_square(sfCircleShape *const cir\
, sfRectangleShape *const sqr, int const radius);

sfRectangleShape *init_hitbox_square(sfSprite *const sprite);

sfCircleShape *init_hitbox_circle(int const radius, sfSprite *sprite);

int check_if_collision_btw_square_without_rotation(sfSprite *const sprite_1\
, sfSprite *const sprite_2);

int check_if_collision_btw_circle_square(int const radius\
, sfSprite *const sprite_circle, sfSprite *const sprite_square);

#endif /* !COLLISION_H_ */
