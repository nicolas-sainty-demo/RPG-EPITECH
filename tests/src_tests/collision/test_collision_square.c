/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** test_collision_square
*/

#include <criterion/criterion.h>

#include <SFML/Graphics/Texture.h>

#include "collision.h"

void is_alloc_null(sfSprite *sprite_1, sfSprite *sprite_2\
, sfTexture *texture_1, sfTexture *texture_2)
{
    cr_assert_not_null(sprite_1);
    cr_assert_not_null(sprite_2);
    cr_assert_not_null(texture_1);
    cr_assert_not_null(texture_2);
}

void free_res(sfSprite *sprite_1, sfSprite *sprite_2\
, sfTexture *texture_1, sfTexture *texture_2)
{
    sfSprite_destroy(sprite_1);
    sfSprite_destroy(sprite_2);
    sfTexture_destroy(texture_1);
    sfTexture_destroy(texture_2);
}

Test(test_collision, no_collision_with_square)
{
    sfSprite *sprite_1 = sfSprite_create();
    sfSprite *sprite_2 = sfSprite_create();
    sfTexture *texture_1 = \
    sfTexture_createFromFile("tests/res/carre.png", NULL);
    sfTexture *texture_2 = \
    sfTexture_createFromFile("tests/res/carre.png", NULL);
    int retour = 0;
    is_alloc_null(sprite_1, sprite_2, texture_1, texture_2);
    sfSprite_setTexture(sprite_1, texture_1, sfTrue);
    sfSprite_setTexture(sprite_2, texture_2, sfTrue);
    sfSprite_setPosition(sprite_1, (sfVector2f){201, 0});
    retour = \
    check_if_collision_btw_square_without_rotation(sprite_1, sprite_2);
    cr_assert(retour == 0);
    free_res(sprite_1, sprite_2, texture_1, texture_2);
}

Test(test_collision, collision_with_square)
{
    sfSprite *sprite_1 = sfSprite_create();
    sfSprite *sprite_2 = sfSprite_create();
    sfTexture *texture_1 = \
    sfTexture_createFromFile("tests/res/carre.png", NULL);
    sfTexture *texture_2 = \
    sfTexture_createFromFile("tests/res/carre.png", NULL);
    int retour = 0;

    is_alloc_null(sprite_1, sprite_2, texture_1, texture_2);
    sfSprite_setTexture(sprite_1, texture_1, sfTrue);
    sfSprite_setTexture(sprite_2, texture_2, sfTrue);
    sfSprite_setPosition(sprite_1, (sfVector2f){199, 0});
    retour = \
    check_if_collision_btw_square_without_rotation(sprite_1, sprite_2);
    cr_assert(retour == 1);
    free_res(sprite_1, sprite_2, texture_1, texture_2);
}