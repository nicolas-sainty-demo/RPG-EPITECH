/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** my_math
*/

#ifndef MY_MATH_H_
#define MY_MATH_H_

#include <math.h>

#include <SFML/System/Vector2.h>

float calc_distance(const float p1, const float p2);

sfVector2f calc_speed_vector(int speed, sfVector2f depart_pos\
, sfVector2f arrival_pos);

#endif /* !MY_MATH_H_ */
