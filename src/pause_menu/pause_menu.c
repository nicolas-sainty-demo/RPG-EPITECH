/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** dead_windows
*/

#include "window_fonction.h"
#include <stdio.h>
#include "button.h"
#include "pause.h"
#include <stdlib.h>

#define RESU_BUTOON "res/dead_menu/resume.png"
#define MENU_BUTTON "res/dead_menu/reset_dead_menu.png"
#define EXIT_BUTTON "res/dead_menu/resit_exit.png"
#define POS_RES (sfVector2f){-180, -220}
#define POS_MENU (sfVector2f){-180, -100}
#define POS_EXIT (sfVector2f){-180, 30}

struct pause_s init_pause_menu()
{
    struct pause_s pause;

    pause.texture = sfTexture_createFromFile
    ("res/image/cobra.png", NULL);
    pause.sprite = sfSprite_create();

    if (pause.texture && pause.sprite)
        sfSprite_setTexture(pause.sprite, pause.texture, sfTrue);
    return (pause);
}

static void set_and_pos(struct pause_s *pause, the_window *windows)
{
    sfRenderWindow_clear(windows->window, sfBlack);
    sfVector2f pos = {-960, -555};

    sfSprite_setPosition(pause->sprite, pos);
    sfRenderWindow_drawSprite(windows->window, \
    pause->sprite , NULL);
}

static void go_menu(void *ptr)
{
    the_window *windows = ptr;

    windows->state = 4;
}

static void go_exit(void *ptr)
{
    the_window *windows = ptr;

    sfRenderWindow_close(windows->window);
}

static void go_resume(void *ptr)
{
    the_window *windows = ptr;

    windows->state = 0;
}

void pause_loop(the_window *windows, struct_button_t *button\
, struct pause_s *pause, int nb)
{
    update_tab_button(windows, button, nb);
    set_and_pos(pause, windows);
    while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
        if (windows->event.type == sfEvtClosed)
            sfRenderWindow_close(windows->window);
        button_tab_event(windows, button, nb);
    }
    button_tab_draw(windows, button, nb);
    sfRenderWindow_display(windows->window);
}

void init_all_buttons(struct_button_t *button)
{
    button[0] = init_button\
    (&go_resume, RESU_BUTOON, POS_RES);
    button[1] = init_button\
    (&go_menu, MENU_BUTTON, POS_MENU);
    button[2] = init_button(&go_exit, EXIT_BUTTON, POS_EXIT);
}

float pause_menu(the_window *windows)
{
    struct pause_s pause = init_pause_menu();
    struct_button_t *button = malloc(sizeof(*button) * 4);
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    init_all_buttons(button);
    windows->click = sfFalse;

    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);
    while (windows->state == 3 && sfRenderWindow_isOpen(windows->window))
        pause_loop(windows, button, &pause, 3);
    sfView_setCenter(windows->camera, camera_center);
    button_tab_free(button, 3);
    sfTexture_destroy(pause.texture);
    sfSprite_destroy(pause.sprite);
    return (time_to_float(timed));
}