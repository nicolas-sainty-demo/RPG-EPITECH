/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_sprite_after_c
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "from_file.h"

sfSprite *get_sprite_after_c(const char *str, const char c)
{
    char *texture_file = get_string_after_c(str, c);
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = NULL;

    if (sprite == NULL || texture_file == NULL)
        return (NULL);
    texture = sfTexture_createFromFile(texture_file, NULL);
    if (texture == NULL)
        return (NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    free(texture_file);
    return (sprite);
}