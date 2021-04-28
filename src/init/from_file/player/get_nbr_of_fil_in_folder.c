/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_nbr_of_fil_in_folder
*/

#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int get_nbr_of_fil_in_folder(char *str)
{
    DIR *folder;
    struct dirent *dirdir = NULL;
    int i = 0;

    folder = opendir(str);
    dirdir = readdir(folder);
    while (dirdir != NULL) {
        if (dirdir->d_name[0] != '.')
            i += 1;
        dirdir = readdir(folder);
    }
    closedir(folder);
    return (i);
}