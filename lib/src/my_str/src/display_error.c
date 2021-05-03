/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** display_error
*/

#include <unistd.h>

int my_strlen(const char *str);

void display_error(const char *str)
{
    write(2, str, my_strlen(str));
}