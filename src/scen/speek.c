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

float speek(the_window *windows, char **conversation)
{
    int i = 0;
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfText *text = init_text("...");
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);

    if (conversation == NULL)
        return (0);
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
    sfView_setCenter(windows->camera, camera_center);
    float save = time_to_float(timed);
    sfText_destroy(text);
    return (save);
}