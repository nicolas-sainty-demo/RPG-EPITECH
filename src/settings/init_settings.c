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

void go_back_to_menu(void *ptr);

void up_song(void *ptr);

void down_song(void *ptr);

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

    button[leave] = init_button(&go_back_to_menu, B_EXIT\
    , (sfVector2f){-150, 0});
    button[down] = init_button(&up_song, B_UP, (sfVector2f){-500, -300});
    button[up] = init_button(&down_song\
    , B_DOWN, (sfVector2f){400, -300});

    if (!button[play].sprite || !button[the_exit].sprite \
    || !button[settings].sprite)
        ret = 84;
    return (ret);
}

main_menu_t init_struct_setting(void)
{
    main_menu_t menu;
    char *path_sprite = SETTING;

    menu.button = malloc(sizeof(*menu.button) * (NB_BUTTON));
    if (!menu.button || set_sprite(path_sprite, &menu.sprites\
    , &menu.texture) == 84)
        return ((main_menu_t){0});
    if (alloc_my_button(menu.button) == 84)
        return ((main_menu_t){0});
    menu.nb_button = NB_BUTTON;
    return (menu);
}