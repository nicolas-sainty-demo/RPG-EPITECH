/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** open_inventory
*/

#include "window_struc.h"
#include "window_fonction.h"
#include "gameplay/inventoryfile.h"

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

void set_and_draw(the_window *windows, sfVector2f view)
{
    sfSprite_setOrigin(windows->inv->inventory_sprite, (sfVector2f){452, 323});
    sfRenderWindow_clear(windows->window, sfBlack);
    sfSprite_setPosition(windows->inv->inventory_sprite, windows->inv->pos_inv);
    sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sprite, NULL);
    for (int i = 0; i != 22; i++) {
        printf("%i\n", i);
        sfSprite_setPosition(windows->inv->inventory_sp_item, inventory_space[i]);
        sfRenderWindow_drawSprite(windows->window, windows->inv->inventory_sp_item, NULL);
    }
    sfRenderWindow_display(windows->window);
}

void verif_close(the_window *windows)
{
    if (windows->event.key.code == sfKeyE)
        windows->state = 0;
}

float inventory_scene(int **tab_stock, the_window *windows)
{
    sfEvent *test;
    sfMouseButton mouse;
    sfClock *timed = sfClock_create();
    sfVector2f camera_center = sfView_getCenter(windows->camera);
    sfView_setCenter(windows->camera, (sfVector2f){0, 0});
    sfRenderWindow_setView(windows->window, windows->camera);

    while (windows->state == 1) {
        set_and_draw(windows, camera_center);
        while (sfRenderWindow_pollEvent(windows->window, &windows->event)) {
            if (windows->event.type == sfEvtClosed)
                sfRenderWindow_close(windows->window);
            if (windows->event.type == sfEvtMouseButtonPressed)
                printf("%f\t\t%f\n", sfRenderWindow_mapPixelToCoords(windows->window, sfMouse_getPositionRenderWindow(windows->window), windows->camera).x, sfRenderWindow_mapPixelToCoords(windows->window, sfMouse_getPositionRenderWindow(windows->window), windows->camera).y);
            if (windows->event.type == sfEvtKeyPressed) {
                verif_close(windows);
            }
        }
    }
    sfView_setCenter(windows->camera, camera_center);
    float save = time_to_float(timed);
    return (save);
}