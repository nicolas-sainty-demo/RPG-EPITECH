/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** speek
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
#include "window_struc.h"
#include "text.h"
#include "time.h"

float time_to_float(sfClock *time);

void remove_item_from_inventory(the_window *windows\
, entity_passive_t *passif, int i);

void leave_quest(the_window *windows, int *i);

static void basic_dialog(the_window *windows, char **conversation)
{
    int i = 0;
    sfText *text = init_text("...");
    sfRenderWindow_setView(windows->window, windows->camera);

    while (conversation[i] != NULL) {
        sfRenderWindow_clear(windows->window, sfBlack);
        sfText_setString(text, conversation[i]);
        sfRenderWindow_drawText(windows->window, text, NULL);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtKeyPressed \
            && windows->event.key.code == sfKeyF)
                i += 1;
        }
        sfRenderWindow_display(windows->window);
    }
    sfText_destroy(text);
}

int quest_is_win(the_window *windows, entity_passive_t *passif, int i)
{
    int j = 0;

    remove_item_from_inventory(windows, passif, i);
    while (passif->quest.item_need[j] != '\0')
        if (passif->quest.item_need[j++] != '!')
            return (0);
    return (1);
}

static void quest_dialog_event\
(the_window *windows, entity_passive_t *passif, int *i)
{
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        leave_quest(windows, i);
        if (windows->event.type == sfEvtKeyPressed \
        && windows->event.key.code == sfKeyY)
            if (quest_is_win(windows, passif, 0)) {
                windows->quest_finiche += 1;
                passif->quest.dialoge = NULL;
                *i = 1;
            }
    }
}

static void quest_dialog(the_window *windows, entity_passive_t *passif)
{
    int i = 0;
    sfText *text = init_text("...");
    sfRenderWindow_setView(windows->window, windows->camera);

    while (i == 0) {
        sfRenderWindow_clear(windows->window, sfBlack);
        sfText_setString(text, passif->quest.dialoge);
        sfRenderWindow_drawText(windows->window, text, NULL);
        quest_dialog_event(windows, passif, &i);
        sfRenderWindow_display(windows->window);
    }
    sfText_destroy(text);
}

float speek(the_window *windows, char **conversation, entity_passive_t *passif)
{
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    float save = 0;

    if (conversation != NULL)
        basic_dialog(windows, conversation);
    if (passif->quest.dialoge != NULL)
        quest_dialog(windows, passif);
    sfView_setCenter(windows->camera, camera_center);
    save = time_to_float(timed);
    sfClock_destroy(timed);
    return (save);
}