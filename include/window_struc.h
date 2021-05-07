/*
** EPITECH PROJECT, 2020
** map_creator_tool
** File description:
** window_struc
*/

#ifndef WINDOW_STRUC_H_
#define WINDOW_STRUC_H_

#include <SFML/Graphics/RenderWindow.h>
#include "scene.h"
#include "struct_button.h"
#include "gameplay/inventory_struct.h"
#include "gameplay/dead_menu_struct.h"

typedef enum state_window_e
{
    in_game,
    in_inventory,
    in_death_menu,
    in_pause,
    in_menu
} state_window_t;


typedef struct the_window
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode Videomode;
    scene_t *scene;
    sfView *camera;
    state_window_t state;
    sfBool click;
    inventory *inv;
    dead_me *d_menu;
} the_window;

#endif /* !WINDOW_STRUC_H_ */
