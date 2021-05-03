/*
** EPITECH PROJECT, 2020
** map_creator_tool
** File description:
** window_struc
*/

#ifndef WINDOW_STRUC_H_
#define WINDOW_STRUC_H_

#include "cfml_include.h"
#include "scene.h"
#include "gameplay/inventory_struct.h"

typedef struct the_window
{
    sfEvent event;
    sfRenderWindow *window;
    sfVideoMode Videomode;
    scene_t *scene;
    sfView *camera;
    int state;
    inventory *inv;
} the_window;

#endif /* !WINDOW_STRUC_H_ */
