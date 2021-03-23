/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision_circle_square
*/

#include <math.h>
#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/CircleShape.h>

static int clamp(int value, int min, int max)
{
    if (value < min)
        return (min);
    else if (value > max)
        return (max);
    else
        return (value);
}

static int do_calc(sfVector2f c_cir, sfVector2f c_sqr, sfFloatRect info_sqr)
{
    sfVector2f test = { 0 };
    sfVector2f dist = { 0 };
    float distance = 0;

    test.x = c_cir.x;
    test.y = c_cir.y;
    test.x = clamp(test.x, c_sqr.x, c_sqr.x + info_sqr.width);
    test.y = clamp(test.y, c_sqr.y, c_sqr.y + info_sqr.height);
    dist.x = c_cir.x - test.x;
    dist.y = c_cir.y - test.y;
    distance = sqrt((dist.x*dist.x) + (dist.y*dist.y));
    return (distance);
}

int is_collision_circle_square(sfCircleShape *const cir\
, sfRectangleShape *const sqr, int const radius)
{
    sfVector2f c_cir = sfCircleShape_getPosition(cir);
    sfVector2f c_sqr = sfRectangleShape_getPosition(sqr);
    sfFloatRect info_sqr = sfRectangleShape_getGlobalBounds(sqr);

    c_cir.x = c_cir.x + radius;
    c_cir.y = c_cir.y + radius;

    float distance = do_calc(c_cir, c_sqr, info_sqr);
    if (distance <= radius) {
        return (1);
    }
    return (0);
}