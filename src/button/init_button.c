/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_button
*/

#include <SFML/Graphics/Sprite.h>

#include "struct_button.h"

struct_button_t init_button(void (*ptr) (void *), char *path, sfVector2f pos)
{
    struct_button_t new_button;
    sfFloatRect bound;

    new_button.ptr = ptr;
    new_button.sprite = sfSprite_create();
    new_button.texture = sfTexture_createFromFile(path, NULL);

    if (!new_button.sprite || !new_button.texture)
        return ((struct_button_t){0});
    new_button.pos = pos;
    sfSprite_setTexture(new_button.sprite, new_button.texture, sfTrue);
    bound = sfSprite_getGlobalBounds(new_button.sprite);
    new_button.bound = (sfIntRect){.width = bound.width, \
    .height = bound.height, .left = 0, .top = 0};
    new_button.width_max = bound.width;
    new_button.bound.width /= 3;
    sfSprite_setTextureRect(new_button.sprite, new_button.bound);
    sfSprite_setPosition(new_button.sprite, new_button.pos);
    return (new_button);
}