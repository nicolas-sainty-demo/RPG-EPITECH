/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** status_menu
*/

/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** menu
*/

#include "window_fonction.h"
#include "struct_menu.h"
#include <stdio.h>
#include "button.h"
#include "text.h"
#include "str.h"
#include <malloc.h>

void go_resume(void *);

static void is_click(the_window *windows)
{
    if (windows->event.type == sfEvtMouseButtonPressed)
        windows->click = sfTrue;
    else
        windows->click = sfFalse;
}

void status_loop(the_window *windows, sfText *text, struct_button_t *button)
{
    update_button(windows, button);
    sfRenderWindow_clear(windows->window, sfBlack);
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        is_click(windows);
        button_event(windows, button);
    }
    sfRenderWindow_drawText(windows->window, text, NULL);
    sfRenderWindow_drawSprite(windows->window, button->sprite, NULL);
    sfRenderWindow_display(windows->window);
}

char *get_setence_with_int(int const nb, char *str, sfBool in_end)
{
    char *buffer = NULL;
    char *current_stat = NULL;

    current_stat = int_to_str(nb);
    if (in_end == sfTrue)
        buffer = my_strcat(current_stat, str);
    else
        buffer = my_strcat(str, current_stat);
    free(current_stat);
    return (buffer);
}

char *set_info_player(player_t *player)
{
    char *buffer = NULL;
    char *current_stat = NULL;
    char *secondary_stat = NULL;
    char *third_stat = NULL;

    buffer = get_setence_with_int(player->damage, " damages\n", sfTrue);
    current_stat = get_setence_with_int(player->hp, "/", sfTrue);
    secondary_stat = get_setence_with_int\
    (player->hp_max, current_stat, sfFalse);
    free(current_stat);
    third_stat = my_strcat(buffer, secondary_stat);
    free(buffer);
    free(secondary_stat);
    return (third_stat);
}

float status_menus(the_window *windows)
{
    sfClock *timed = sfClock_create();
    struct_button_t button_exit = init_button\
    (&go_resume, EXIT_BUTTON, (sfVector2f){100, 100});
    sfText *status = init_text(set_info_player(windows->scene->player));
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    windows->click = sfFalse;

    if (!timed || !status)
        return (0);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);
    while (windows->state == in_status \
    && sfRenderWindow_isOpen(windows->window))
        status_loop(windows, status, &button_exit);
    sfView_setCenter(windows->camera, camera_center);
    free_button(&button_exit);
    sfClock_destroy(timed);
    sfText_destroy(status);
    return (time_to_float(timed));
}