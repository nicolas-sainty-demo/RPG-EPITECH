/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** init_text_button
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stddef.h>

sfText *init_text(const char *str)
{
    sfText *score = sfText_create();
    sfFont *font = sfFont_createFromFile("res/text/score.otf");

    if (score == NULL || font == NULL)
        return (NULL);
    sfText_setFont(score, font);
    sfText_setString(score, str);
    return (score);
}