/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** get_inventaire_from_file
*/

#include "scene.h"
#include "str.h"
#include "stdlib.h"
#include <dirent.h>
#include "from_file.h"
#include <sys/types.h>

void get_char_from_file\
(char **string, const char *name_of_dir, const char *name_of_file)
{
    char *file = my_strcat(name_of_dir, name_of_file);

    *string = NULL;
    if (file == NULL || my_reader(file, string) == 84)
        *string = NULL;
    free(file);
}