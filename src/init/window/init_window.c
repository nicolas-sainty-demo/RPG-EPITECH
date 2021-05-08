/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_window
*/

#include "window_struc.h"
#include "button.h"
#include <SFML/Graphics/View.h>

main_menu_t init_struct_menu(void);

main_menu_t init_struct_setting(void);

the_window init_window(const int x, const int y)
{
    the_window windows;

    windows.quest_finiche = 0;
    windows.Videomode = (sfVideoMode){x, y, 32};
    windows.window = sfRenderWindow_create\
    (windows.Videomode, "Nom de la fenaitre", sfClose | sfNone, NULL);
    sfRenderWindow_setFramerateLimit(windows.window, 60);
    sfRenderWindow_setMouseCursorVisible(windows.window, sfTrue);
    windows.scene = NULL;
    windows.camera = sfView_create();
    sfRenderWindow_setView(windows.window, windows.camera);
    sfView_setSize(windows.camera, (sfVector2f){x, y});
    windows.m_menu = init_struct_menu();
    windows.settings = init_struct_setting();
    windows.volume_min_max = (sfVector2f){0, 100};
    windows.volume = 0;
    return (windows);
}