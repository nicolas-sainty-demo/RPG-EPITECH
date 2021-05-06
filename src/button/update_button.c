/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_button
*/

#include "window_struc.h"

#include "button.h"

static void check_condition_buttons(struct_button_t *button, the_window *p)
{
    if ((*button).state == released) {
        (*button).ptr(p);
    }
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

static void is_rect_need_to_change(struct_button_t *button, the_window *p\
, sfVector2i pos_mouse)
{
    sfFloatRect bound_sprite = sfSprite_getGlobalBounds(button->sprite);

    if (sfFloatRect_contains(&bound_sprite, pos_mouse.x, pos_mouse.y)\
     == sfTrue) {
        check_condition_buttons(button, p);
    }
    else {
        button->bound.left = 0;
        sfSprite_setTextureRect(button->sprite, button->bound);
    }
    button->state = normal;
}

void update_button(the_window *p, struct_button_t *button)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(p->window);

    is_rect_need_to_change(button, p, pos_mouse);
}

void button_event(the_window *p, struct_button_t *button)
{
    if (p->event.type == sfEvtMouseButtonReleased)
        button->state = released;
}