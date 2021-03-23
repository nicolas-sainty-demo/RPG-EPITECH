/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** my_str_is_num
*/

int str_is_num(const char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
    }
    return (1);
}