/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** can_in_int
*/

#include <stdlib.h>

#include <SFML/System/Vector2.h>

int height_int_map(int *const *map)
{
    int height = 0;

    if (!map)
        return (height);
    while (map[height++] != NULL);
    return (height);
}

int my_strlen_int(int *const map)
{
    int len = 0;

    if (!map)
        return (len);
    while (map[len] != 0)
        len++;
    return (len);
}

int can_in_int_map(sfVector2i pos, int **map)
{
    int x_max = 0;

    if (pos.x < 0 || pos.y < 0)
        return (0);
    if (pos.y < height_int_map(map)) {
        x_max = my_strlen_int(map[pos.y]);
        if (pos.x < x_max) {
            return (1);
        }
    }
    return (0);
}