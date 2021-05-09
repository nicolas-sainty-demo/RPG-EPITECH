/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** test_drop_item
*/

#include <criterion/criterion.h>

#include "window_struc.h"

int drop_the_item(items_t **pos_items, sfSprite *sprite);

Test(test_drop_item, add_item)
{
    items_t *pos_items = NULL;
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(100, 100);
    int ret = 0;

    cr_assert_not_null(sprite);
    cr_assert_not_null(texture);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setPosition(sprite, (sfVector2f){0, 0});
    ret = drop_the_item(&pos_items, sprite);
    cr_assert(ret == 0);
    cr_assert(pos_items->pos.x == 50);
    cr_assert(pos_items->pos.y == 50);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
}