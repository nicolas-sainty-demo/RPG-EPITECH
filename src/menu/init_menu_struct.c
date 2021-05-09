/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_menu_struct
*/

#include <malloc.h>
#include <stdio.h>
#include "window_fonction.h"
#include "struct_menu.h"
#include "button.h"

void menu_play(void *ptr);

void menu_exit(void *ptr);

void menu_settings(void *ptr);

static int set_sprite(char *const path, sfSprite **sprites\
, sfTexture **textures)
{
    (*sprites) = sfSprite_create();
    (*textures) = sfTexture_createFromFile(path, sfFalse);

    if (!(*sprites) || !(*textures))
        return (84);
    sfSprite_setTexture((*sprites), (*textures), sfFalse);
    return (0);
}

static int alloc_my_button(struct_button_t *button)
{
    int ret = 0;

    button[play] = init_button(&menu_play, B_PLAY, (sfVector2f){100, 100});
    button[the_exit] = init_button(&menu_exit, B_EXIT, (sfVector2f){100, 340});
    button[settings] = init_button(&menu_settings\
    , B_SETTING, (sfVector2f){100, 220});

    if (!button[play].sprite || !button[the_exit].sprite \
    || !button[settings].sprite)
        ret = 84;
    return (ret);
}

main_menu_t init_struct_menu(void)
{
    main_menu_t menu;
    char *path_sprite = BACKGRND;

    menu.button = malloc(sizeof(*menu.button) * (NB_BUTTON + 1));
    if (!menu.button || set_sprite(path_sprite, &menu.sprites\
    , &menu.texture) == 84)
        return ((main_menu_t){0});
    if (alloc_my_button(menu.button) == 84)
        return ((main_menu_t){0});
    menu.nb_button = NB_BUTTON;
    return (menu);
}