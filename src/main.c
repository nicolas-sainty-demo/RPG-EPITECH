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

int main(int argc, char const *argv[])
{
    return (core());
}
