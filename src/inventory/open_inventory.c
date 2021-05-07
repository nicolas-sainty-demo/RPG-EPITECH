/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** open_inventory
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "gameplay/inventoryfile.h"
#include <stdio.h>
#include "str.h"

void init_inventory(inventory *inv)
{
    inv->inventory_texture = sfTexture_createFromFile
    ("res/inventory/inventaire_rpg.png", NULL);
    inv->inventory_sprite = sfSprite_create();
    sfSprite_setTexture(inv->inventory_sprite, inv->inventory_texture, sfTrue);
    inv->inventory_te_item = sfTexture_createFromFile
    ("res/inventory/test_item.png", NULL);
    inv->inventory_sp_item = sfSprite_create();
    sfSprite_setTexture(inv->inventory_sp_item, inv->inventory_te_item, sfTrue);
}

void set_and_draw(the_window *windows, const int position_cursor, char **item_select, const int key_press)
{
    sfSprite_setOrigin(windows->inv->inventory_sprite, (sfVector2f){452, 323});
    sfRenderWindow_clear(windows->window, sfBlack);
    sfSprite_setPosition(windows->inv->inventory_sprite, windows->inv->pos_inv);
    sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sprite, NULL);
    for (int i = 0; i != 22; i++) {
        sfSprite_setTextureRect(windows->inv->inventory_sp_item, (sfIntRect)\
        {(windows->scene->player->inventaire[i] - 33) * 90, 0, 90, 90});
        sfSprite_setPosition(windows->inv->inventory_sp_item, inventory_space[i]);
        sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sp_item, NULL);
        if (i == position_cursor) {
            if (key_press == SELECT_KEY)
                *item_select = &windows->scene->player->inventaire[i];
            sfSprite_setTextureRect(windows->inv->inventory_sp_item, (sfIntRect)\
            {(26) * 90, 0, 90, 90});
            sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sp_item, NULL);
        }
    }
    sfSprite_setTextureRect(windows->inv->inventory_sp_item, (sfIntRect)\
    {(**item_select - 33) * 90, 0, 90, 90});
    sfSprite_setPosition(windows->inv->inventory_sp_item, selec_space);
    sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sp_item, NULL);
    sfRenderWindow_display(windows->window);
}

void verif_key(the_window *windows, int *key_press)
{
    if (windows->event.type == sfEvtKeyPressed) {
        if (windows->event.key.code == sfKeyE)
            windows->state = in_game;
        if (windows->event.key.code == sfKeyA)
            *key_press = SELECT_KEY;
        if (windows->event.key.code == sfKeyF)
            *key_press = USE_KEY;
        if (windows->event.key.code == sfKeyJ)
            *key_press = DROP_KEY;
        if (windows->event.key.code == sfKeyG)
            *key_press = EAT_KEY;
    }
}

int cursor_move(the_window *windows)
{
    if (windows->event.type == sfEvtClosed)
        sfRenderWindow_close(windows->window);
    if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyD)
        return (1);
    if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyQ)
        return (-1);
    if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyS)
        return (5);
    if (windows->event.type == sfEvtKeyPressed && windows->event.key.code == sfKeyZ)
        return (-5);
    return (0);
}

void switch_in_invantory(char *a, char *b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

void use_and_drop_item(const int key_press, char *item_select, the_window *windows, int position_cursor)
{
    if (key_press == DROP_KEY)
        *item_select = '!';
    if (key_press == USE_KEY)
        switch_in_invantory(item_select, &windows->scene->player->inventaire[position_cursor]);
    if (key_press == EAT_KEY) {
        if (c_is_in_str(*item_select, food_list)) {
            printf("CRUNCHE!!!\n");
            *item_select = '!';
        }
    }
}

float inventory_scene(int **tab_stock, the_window *windows)
{
    char *item_select = &windows->scene->player->inventaire[0];
    int key_press = 0;
    int position_cursor = 0;
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);

    while (windows->state == in_inventory && sfRenderWindow_isOpen(windows->window)) {
        set_and_draw(windows, position_cursor, &item_select, key_press);
        use_and_drop_item(key_press, item_select, windows, position_cursor);
        key_press = 0;
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            position_cursor += cursor_move(windows);
            if (windows->event.type == sfEvtMouseButtonPressed) {
                printf("%f\t\t%f\n", sfRenderWindow_mapPixelToCoords(windows->window, sfMouse_getPositionRenderWindow(windows->window), windows->camera).x, sfRenderWindow_mapPixelToCoords(windows->window, sfMouse_getPositionRenderWindow(windows->window), windows->camera).y);
            }
            verif_key(windows, &key_press);
        }
        if (position_cursor < 0 || position_cursor > 21)
            position_cursor = 0;
    }
    sfView_setCenter(windows->camera, camera_center);
    float save = time_to_float(timed);
    return (save);
}