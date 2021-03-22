/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision_circle
*/

#include <math.h>
#include <SFML/Graphics.h>

static sfVector2f get_mid_position_circle(sfVector2f pos, const int radius)
{
    pos.x += radius;
    pos.y += radius;
    return (pos);
}

static sfVector2f get_distance_for_point(sfVector2f point1, sfVector2f point2)
{
    sfVector2f distance = { 0 };

    distance.x = point1.x - point2.x;
    distance.y = point1.y - point2.y;
    return (distance);
}

int is_collision_circles(sfCircleShape *const cir_1\
, int const radius_1, sfCircleShape *const cir_2, int const radius_2)
{
    sfVector2f c_cir_1 = sfCircleShape_getPosition(cir_1);
    sfVector2f c_cir_2 = sfCircleShape_getPosition(cir_2);
    sfVector2f dist = { 0 };
    int distance = 0;

    c_cir_1 = get_mid_position_circle(c_cir_1, radius_1);
    c_cir_2 = get_mid_position_circle(c_cir_2, radius_2);
    dist = get_distance_for_point(c_cir_1, c_cir_2);
    distance = sqrt(dist.x * dist.x + dist.y * dist.y);
    if (distance < radius_1 + radius_2)
        return (1);
    return (0);
}