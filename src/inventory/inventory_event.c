/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** inventory_event
*/

#include "key.h"
#include "window_struc.h"

void event_interaction_iventory(the_window *windows, int *key_press)
{
    if (windows->event.key.code == sfKeyF)
        *key_press = USE_KEY;
    if (windows->event.key.code == sfKeyJ)
        *key_press = DROP_KEY;
    if (windows->event.key.code == sfKeyG)
        *key_press = EAT_KEY;
}

int event_movement_cursor(the_window *windows)
{
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyQ)
        return (-1);
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyS)
        return (5);
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyZ)
        return (-5);
    return (0);
}
