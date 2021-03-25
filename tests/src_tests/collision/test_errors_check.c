/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** test_errors_check
*/

#include <criterion/criterion.h>

#include <SFML/Graphics/Texture.h>

#include "collision.h"

void is_alloc_null(sfSprite *sprite_1, sfSprite *sprite_2\
, sfTexture *texture_1, sfTexture *texture_2);

void free_res(sfSprite *sprite_1, sfSprite *sprite_2\
, sfTexture *texture_1, sfTexture *texture_2);

Test(test_collision, null_collision_square_circle)
{
    int retour = check_if_collision_btw_circle_square(50, NULL, NULL);
    cr_assert(retour == 0);
}

Test(test_collision, null_collision_square)
{
    int retour = \
    check_if_collision_btw_square_without_rotation(NULL, NULL);
    cr_assert(retour == 0);
}

Test(test_collision, collision_with_circle)
{
    int retour = \
    check_if_collision_btw_circles(NULL, 0, NULL, 0);
    cr_assert(retour == 0);
}