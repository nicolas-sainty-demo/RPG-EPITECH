/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** main
*/

#include "window_fonction.h"
#include "str.h"

int core(void)
{
    the_window windows = init_window(1920, 1080);

    default_page(&windows);
    return (0);
}

int main(int argc, char const *argv[])
{
    return (core());
}
