/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** my_strcmp
*/

int my_strlen(char *const str);

int my_strlen_to_c(const char *str, char c);

int my_strcmp(char *str, char *dest)
{
    int i = 0;
    int a = my_strlen(str);
    int b = my_strlen(dest);

    if (a - b != 0)
        return (0);
    while (str[i] != '\0' && dest[i] != '\0') {
        if (dest[i] != str[i])
            return (0);
        i++;
    }
    return (1);
}

int my_strcmp_to_c(char *str, char *dest, char c)
{
    int i = 0;
    int a = my_strlen_to_c(str, c);
    int b = my_strlen_to_c(dest, c);

    if (a - b != 0)
        return (0);
    while (str[i] != '\0' && dest[i] != '\0' && str[i] != c && dest[i] != c) {
        if (dest[i] != str[i])
            return (0);
        i++;
    }
    return (1);
}
