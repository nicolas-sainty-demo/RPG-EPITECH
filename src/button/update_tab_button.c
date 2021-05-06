/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** update_tab_button
*/

#include "button.h"

void update_tab_button(the_window *p, struct_button_t ***button)
{
    for (int i = 0; (*button)[i]; i++) {
        update_button(p, (*button)[i]);
    }
}

void button_tab_event(the_window *p, struct_button_t ***button)
{
    for (int i = 0; (*button[i]); i++) {
        if (p->event.type == sfEvtMouseButtonReleased)
            (*button)[i]->state = released;
    }
    
}