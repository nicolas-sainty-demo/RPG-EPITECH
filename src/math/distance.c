/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** distance
*/

#include <math.h>

#include <SFML/System/Vector2.h>

float calc_distance(const float p1, const float p2)
{
    return (sqrt(pow(p1, 2) + pow(p2, 2)));
}

sfVector2f calc_speed_vector(const int speed, const sfVector2f depart_pos\
, const sfVector2f arrival_pos)
{
    sfVector2f vector_speed = { 0 };
    float delta_x = arrival_pos.x - depart_pos.x;
    float delta_y = arrival_pos.y - depart_pos.y;
    float distance = calc_distance(delta_x, delta_y);

    if (distance != 0) {
        vector_speed.x = (fabs(delta_x / distance) * speed);
        vector_speed.y = (fabs(delta_y / distance) * speed);
    }
    if (arrival_pos.x < depart_pos.x)
        vector_speed.x *= -1;
    if (arrival_pos.y < depart_pos.y)
        vector_speed.y *= -1;
    return (vector_speed);
}