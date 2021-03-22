/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** strdup_int
*/

#include <stdlib.h>

int *strdup_int(int *const array, int const size_array)
{
    int *new_array = malloc(sizeof(int) * size_array);

    if (!new_array || size_array == 0)
        return (NULL);
    for (int i = 0; i < size_array; i++) {
        new_array[i] = array[i];
    }
    return (new_array);
}