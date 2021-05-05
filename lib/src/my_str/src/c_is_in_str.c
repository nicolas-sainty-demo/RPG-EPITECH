/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** c_is_in_str
*/

int c_is_in_str(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c)
            return (1);
    }
    return (0);
}