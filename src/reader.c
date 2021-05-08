/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** reader
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int read_information(char **buffer, struct stat size, int fd)
{
    ssize_t stock = 0;

    if ((*buffer) == NULL)
        return (-1);
    stock = read(fd, (*buffer), size.st_size);
    if (stock == - 1)
        return (-1);
    return (stock);
}

int my_reader(const char *nom, char **buffer)
{
    ssize_t stock = 0;
    struct stat size;
    int fd = open(nom, O_RDONLY);

    if (fd < 0)
        return (84);
    if (stat(nom, &size) == -1 || S_ISDIR(size.st_mode))
        return (84);
    *buffer = malloc(sizeof(char) * (size.st_size ) + 1);
    if ((*buffer) == NULL)
        return (-1);
    stock = read(fd, (*buffer), size.st_size);
    if (stock == - 1)
        return (-1);
    (*buffer)[stock] = '\0';
    return (0);
}