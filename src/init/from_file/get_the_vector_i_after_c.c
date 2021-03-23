/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_the_vector_i_after_c
*/

#include "from_file.h"
#include "str.h"
#include "stdlib.h"
#include <SFML/System/Vector2.h>

sfVector2i get_the_vector_i_after_c(const char *str, const char c)
{
    sfVector2i vector = { 0 };
    char *str_nbr = get_string_after_c(str, c);
    char **tab = str_to_a_tab(str_nbr, ',');

    if (tab == NULL || get_tab_max(tab) < 2 || !str_is_num(tab[0]) \
    || !str_is_num(tab[1]))
        return (vector);
    vector.x = my_get_nbr(tab[0], 10);
    vector.y = my_get_nbr(tab[1], 10);
    free(str_nbr);
    return (vector);
}