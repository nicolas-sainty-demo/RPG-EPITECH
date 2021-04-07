/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** main
*/

#include "window_fonction.h"
#include "str.h"
#include "from_file.h"

int core(void)
{
    the_window windows = init_window(1920, 1080);

    windows.scene = get_scene_from_folder("res/scene/debut");
    default_page(&windows);
    return (0);
}

int is_env(char **env)
{
    int is_display = 0;

    if (env == NULL)
        return (84);
    for (int i = 0; env[i]; i++) {
        if (my_strcmp(env[i], "DISPLAY"))
            is_display++;
    }
    if (is_display)
        return (0);
    return (84);
}

int main(int argc, char const *argv[], char **env)
{
    if (is_env(env) == 84)
        return (84);
    return (core());
}
