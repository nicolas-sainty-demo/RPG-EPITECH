/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision
*/

#ifndef COLLISION_H_
#define COLLISION_H_

#include <SFML/Graphics/Sprite.h>

#include <SFML/Graphics/RenderWindow.h>

#include <SFML/Graphics/Color.h>

int is_collision_square_without_rotation(sfRectangleShape *const sqr_1\
, sfRectangleShape *const sqr_2);

int is_collision_circle_square(sfCircleShape *const cir\
, sfRectangleShape *const sqr, int const radius);

int is_collision_circles(sfCircleShape *const cir_1\
, int const radius_1, sfCircleShape *const cir_2, int const radius_2);

sfRectangleShape *init_hitbox_square(sfSprite *const sprite);

sfCircleShape *init_hitbox_circle(int const radius, sfSprite *sprite);

int check_if_collision_btw_square_without_rotation(sfSprite *const sprite_1\
, sfSprite *const sprite_2);

int check_if_collision_btw_circle_square(int const radius\
, sfSprite *const sprite_circle, sfSprite *const sprite_square);

int check_if_collision_btw_circles(sfSprite *const sprite_circle_1\
, int const radius_1, sfSprite *const sprite_circle_2, int const radius_2);

void free_hitbox_circle(sfCircleShape *hitbox_circle);

void free_hitbox_square(sfRectangleShape *hitbox_sprite);

void display_circle_hitbox_debug(int const radius, sfSprite *sprite\
, sfRenderWindow *windows, sfColor color);

void display_square_hitbox_debug(sfSprite *sprite, sfRenderWindow *windows\
, sfColor color);

#endif /* !COLLISION_H_ */
