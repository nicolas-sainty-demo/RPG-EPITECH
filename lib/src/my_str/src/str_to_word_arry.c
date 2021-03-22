/*
** EPITECH PROJECT, 2021
** sdfgdsfsdg
** File description:
** str_to_word_arry
*/

#include <stdlib.h>

int my_strlen(const char *str);

int nbr_of_this_char(const char *str, const char c)
{
    int i = 0;

    if (str == NULL)
        return (0);
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == c)
            i++;
    }
    return (i);
}

int len_of_words(const char c, int i, const char *str)
{
    int ret = 0;

    while (str[i] != '\0' && str[i] != c) {
        i++;
        ret++;
    }
    return (ret);
}

static int copy(const char *str, const char c, char **tab)
{
    int j = 0;
    int k = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        tab[j] = malloc(sizeof(char) * (len_of_words(c, i , str) + 1));
        if (tab[j] == NULL)
            return (84);
        while (tab[j] != NULL && str[i] != c && str[i] != '\0') {
            tab[j][k++] = str[i++];
        }
        tab[j++][k] = '\0';
        k = 0;
    }
    tab[j] = NULL;
    return (0);
}

char **str_to_a_tab(const char *str, const char c)
{
    char **tab = malloc(sizeof(char *) * (nbr_of_this_char(str, c) + 3));

    if (tab == NULL || str == NULL)
        return (NULL);
    copy(str, c, tab);
    return (tab);
}