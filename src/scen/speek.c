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
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyF)
                i += 1;
        }
        sfRenderWindow_display(windows->window);
    }
    sfText_destroy(text);
}

int quest_is_win(the_window *windows, entity_passive_t *passif)
{
    int i = 0;
    int j = 0;

    while (passif->quest.item_need[j])
    {
        while (windows->scene->player->inventaire[i] != '\0') {
            if (passif->quest.item_need[j] == windows->scene->player->inventaire[i]) {
                passif->quest.item_need[j] = '!';
                windows->scene->player->inventaire[i] = '!';
            }
            i += 1;
        }
        i = 0;
        j += 1;
    }
    j = 0;
    while (passif->quest.item_need[j] != '\0') {
        if (passif->quest.item_need[j] != '!')
            return (0);
        j += 1;
    }
    return (1);
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
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyF)
                i = 1;
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyY)
                if (quest_is_win(windows, passif)) {
                    windows->quest_finiche += 1;
                    passif->quest.dialoge = NULL;
                    i = 1;
                }
            if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyN)
                i = 1;
        }
        sfRenderWindow_display(windows->window);
    }
    sfText_destroy(text);
}

float speek(the_window *windows, char **conversation, entity_passive_t *passif)
{
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});

    if (conversation != NULL)
        basic_dialog(windows, conversation);
    if (passif->quest.dialoge != NULL)
        quest_dialog(windows, passif);
    sfView_setCenter(windows->camera, camera_center);
    float save = time_to_float(timed);
    return (save);
}