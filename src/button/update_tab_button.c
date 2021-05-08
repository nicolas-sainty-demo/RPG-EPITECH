/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_tab_button
*/

#include "button.h"
#include <malloc.h>

void update_tab_button(the_window *p, struct_button_t *button, int const nb)
{
    for (int i = 0; i < nb; i++) {
        update_button(p, &button[i]);
    }
}

void button_tab_event(the_window *p, struct_button_t *button, int const nb)
{
    for (int i = 0; i < nb; i++) {
        if (p->event.type == sfEvtMouseButtonReleased)
            button[i].state = released;
    }    
}

void button_tab_draw(the_window *p, struct_button_t *button, int const nb)
{
    for (int i = 0; i < nb; i++) {
        sfRenderWindow_drawSprite(p->window, button[i].sprite, NULL);
    }
}

void button_tab_free(struct_button_t *button, int const nb)
{
    for (int i = 0; i < nb; i++) {
        free_button(&button[i]);
    }
    free(button);
}