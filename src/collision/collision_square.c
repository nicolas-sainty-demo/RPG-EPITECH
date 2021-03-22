/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** collision_square
*/

#include <SFML/Graphics/RectangleShape.h>

int is_collision_square_without_rotation(sfRectangleShape *const sqr_1\
, sfRectangleShape *const sqr_2)
{
    sfVector2f pos_sqr_1 = sfRectangleShape_getPosition(sqr_1);
    sfVector2f pos_sqr_2 = sfRectangleShape_getPosition(sqr_2);
    sfFloatRect info_sqr_1 = sfRectangleShape_getGlobalBounds(sqr_1);
    sfFloatRect info_sqr_2 = sfRectangleShape_getGlobalBounds(sqr_2);

    if (pos_sqr_1.x < pos_sqr_2.x + info_sqr_2.width && \
    pos_sqr_1.x + info_sqr_1.width > pos_sqr_2.x && \
    pos_sqr_1.y < pos_sqr_2.y + info_sqr_2.height && \
    pos_sqr_1.y + info_sqr_1.height > pos_sqr_2.y)
        return (1);
    return (0);
}