/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_the_int_after_c
*/

#include "from_file.h"
#include "str.h"
#include "stdlib.h"

int get_the_int_after_c(const char *str, const char c)
{
    char *str_nbr = get_string_after_c(str, c);
    int retour = 0;

    if (str_nbr == NULL || !str_is_num(str_nbr))
        return (0);
    retour = my_get_nbr(str_nbr, 10);
    free(str_nbr);
    return (retour);
}