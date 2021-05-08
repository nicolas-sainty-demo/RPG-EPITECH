/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** main
*/

#include <stdlib.h>
#include "window_fonction.h"
#include "gameplay/inventory.h"
#include "gameplay/dead_menu.h"
#include "gameplay/win_menu.h"
#include "str.h"
#include <time.h>
#include <SFML/Graphics.h>

void init_inventory(inventory *inv);

int is_env(char **env);

int core(void)
{
    the_window windows = init_window(1920, 1080);
    inventory *inv = init_struct();
    dead_me *d_menu = init_struct_dead_menu();
    win_me *w_menu = init_struct_win_menu();
    init_inventory(inv);
    init_dead_menu(d_menu);
    init_win_menu(w_menu);
    windows.inv = inv;
    windows.d_menu = d_menu;
    windows.w_menu = w_menu;

    default_page(&windows);
    return (0);
}

int main(int argc, char const *argv[], char **env)
{
    srand(time(NULL));
    if (is_env(env) == 84)
        return (84);
    return (core());
}