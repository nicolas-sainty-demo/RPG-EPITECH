/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** init_menu_struct
*/

#include "window_fonction.h"
#include "struct_menu.h"
#include <stdio.h>
#include "button.h"

#define NB_SPRITE 2
#define BACKGRND "res/menu/fonts/background.png"
#define SETTING "res/menu/fonts/menu.png"
#define NB_BUTTON 5

static void set_sprite(char *const path, sfSprite **sprites\
, sfTexture **textures, int index)
{
    sprites[index] = sfSprite_create();
    textures[index] = sfTexture_createFromFile(path, sfFalse);

    if (!sprites[index] || !textures[index])
        return;
    sfSprite_setTexture(sprites[index], textures[index], sfFalse);
}

void alloc_my_button(struct_button_t **)
{
    ;
}

main_menu_t init_struct_menu(void)
{
    main_menu_t menu;
    int i = 0;
    char *path_sprites[] = {BACKGRND, SETTING, NULL};

    menu.sprites = malloc(sizeof(*menu.sprites) * (NB_SPRITE + 1));
    menu.texture = malloc(sizeof(*menu.texture) * (NB_SPRITE + 1));
    menu.button = malloc(sizeof(*menu.button) * (NB_BUTTON + 1));
    if (!menu.sprites || !menu.texture || !menu.button)
        return ((main_menu_t){0});
    while (path_sprites[i]) {
        set_sprite(path_sprites[i], menu.sprites, menu.texture, i);
        i++;
    }
    menu.sprites[i] = NULL;
    menu.texture[i] = NULL;
}