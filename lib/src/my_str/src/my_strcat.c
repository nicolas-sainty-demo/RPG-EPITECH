/*
** EPITECH PROJECT, 2021
** B-CPE-110-BDX-1-1-antman-jude.marzat
** File description:
** my_strcat
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *const dest, char *const str)
{
    int i = 0;
    int j = 0;
    char *fus = malloc(sizeof(char) * (my_strlen(str) + my_strlen(dest) + 1));

    if (dest == NULL || fus == NULL)
        return (NULL);
    while (dest != NULL && dest[i] != '\0') {
        fus[i] = dest[i];
        i++;
    }
    while (str != NULL && str[j] != '\0') {
        fus[i] = str[j];
        j++;
        i++;
    }
    fus[i] = '\0';
    return (fus);
}