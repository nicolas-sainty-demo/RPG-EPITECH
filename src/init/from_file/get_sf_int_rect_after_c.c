/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_sf_int_rect
*/

#include "from_file.h"
#include "str.h"
#include "stdlib.h"
#include <SFML/System/Vector2.h>

sfIntRect get_sf_int_rect_after_c(const char *str, const char c)
{
    sfIntRect rec = { 0 };
    char *str_nbr = get_string_after_c(str, c);
    char **tab = str_to_a_tab(str_nbr, ',');

    if (tab == NULL || get_tab_max(tab) < 4 || !str_is_num(tab[0]) \
    || !str_is_num(tab[1]) || !str_is_num(tab[2]) || !str_is_num(tab[3]))
        return (rec);
    rec.left = my_get_nbr(tab[0], 10);
    rec.top = my_get_nbr(tab[1], 10);
    rec.width = my_get_nbr(tab[2], 10);
    rec.height = my_get_nbr(tab[3], 10);
    free(str_nbr);
    return (rec);
}