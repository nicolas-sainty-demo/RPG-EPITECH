/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_button
*/

#include "window_struc.h"

#include "button.h"

static void is_need_to_rect(struct_button_t *button, the_window *p)
{
    if ((*button).state == released)
        (*button).ptr(p);
    if (p->click == sfTrue) {
        button->bound.left = button->bound.width * 2;
        sfSprite_setTextureRect((*button).sprite, button->bound);
        (*button).state = click;
        return;
    }
    else {
        button->bound.left = button->bound.width;
        sfSprite_setTextureRect((*button).sprite, button->bound);
    }
}

static void change_the_rec(struct_button_t *button, the_window *p\
, sfVector2f pos_mouse)
{
    sfFloatRect bound_sprite = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains\
    (&bound_sprite, pos_mouse.x, pos_mouse.y) == sfTrue) {
        is_need_to_rect(button, p);
    }
    else {
        button->bound.left = 0;
        sfSprite_setTextureRect(button->sprite, button->bound);
    }
    button->state = normal;
}

void update_button(the_window *p, struct_button_t *button)
{
    sfVector2i pos_mouse = { 0 };
    sfVector2f pos_mouse_coords = { 0 };
    pos_mouse = sfMouse_getPositionRenderWindow(p->window);
    pos_mouse_coords = sfRenderWindow_mapPixelToCoords(p->window\
    , pos_mouse, p->camera);

    change_the_rec(button, p, pos_mouse_coords);
}

void button_event(the_window *p, struct_button_t *button)
{
    if (p->event.type == sfEvtMouseButtonReleased)
        button->state = released;
}

void free_button(struct_button_t *button)
{
    sfSprite_destroy(button->sprite);
    sfTexture_destroy(button->texture);
}