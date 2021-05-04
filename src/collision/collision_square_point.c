/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision_square_point
*/

#include <SFML/Graphics/RectangleShape.h>

int is_collision_square_point(sfRectangleShape *const sqr_1\
, sfVector2f pt)
{
    sfFloatRect info_sqr_1 = sfRectangleShape_getGlobalBounds(sqr_1);

    if (sfFloatRect_contains(&info_sqr_1, pt.x, pt.y))
        return (sfTrue);
    return (sfFalse);
}