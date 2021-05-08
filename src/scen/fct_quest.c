/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** fct_quest
*/

#include <stddef.h>
#include "window_struc.h"
#include "text.h"
#include "time.h"

void remove_item_from_inventory(the_window *windows\
, entity_passive_t *passif, int i)
{
    int j = 0;

    while (passif->quest.item_need[j]) {
        while (windows->scene->player->inventaire[i] != '\0') {
            if (passif->quest.item_need[j] \
            == windows->scene->player->inventaire[i]) {
                passif->quest.item_need[j] = '!';
                windows->scene->player->inventaire[i] = '!';
            }
            i += 1;
        }
        i = 0;
        j += 1;
    }
}

void leave_quest(the_window *windows, int *i)
{
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyF)
        *i = 1;
    if (windows->event.type == sfEvtKeyPressed \
    && windows->event.key.code == sfKeyN)
        *i = 1;
}