/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** struct_button
*/

#ifndef STRUCT_BUTTON_H_
#define STRUCT_BUTTON_H_

#include <SFML/Graphics/Texture.h>

enum state_button_e
{
    normal,
    click,
    released
};

typedef struct struct_button_s
{
    sfSprite *sprite;
    sfTexture *texture;
    enum state_button_e state;
    sfVector2f pos;
    sfIntRect bound;
    int width_max;
    void (*ptr) (void *);
} struct_button_t;


#endif /* !STRUCT_BUTTON_H_ */
