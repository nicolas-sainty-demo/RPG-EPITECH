/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** main
*/

#include "window_fonction.h"
#include "gameplay/inventory.h"
#include "gameplay/dead_menu.h"
#include "str.h"
#include <time.h>
#include <SFML/Graphics.h>

int core(void)
{
    the_window windows = init_window(1920, 1080);
    inventory *inv = init_struct();
    dead_me *d_menu = init_struct_dead_menu();
    init_inventory(inv);
    init_dead_menu(d_menu);
    windows.inv = inv;
    windows.d_menu = d_menu;

    default_page(&windows);
    return (0);
}

int my_strstr(char *const haystack, char *const needle)
{
    int i = 0;
    int j = 0;

    if (!haystack || !needle)
        return (0);
    while (haystack[i] && needle[j]) {
        if (haystack[i] == needle[j])
            j++;
        i++;
    }
    if (j == my_strlen(needle))
        return (1);
    return (0);
}

int is_env(char **env)
{
    int is_display = 0;

    if (env == NULL)
        return (84);
    for (int i = 0; env[i]; i++) {
        if (my_strstr(env[i], "DISPLAY"))
            is_display++;
    }
    if (is_display)
        return (0);
    return (84);
}

int main(int argc, char const *argv[], char **env)
{
    srand(time(NULL));
    if (is_env(env) == 84)
        return (84);
    return (core());
}