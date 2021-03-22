/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-mydefender-jude.marzat
** File description:
** str
*/

#ifndef STR_H_
#define STR_H_

#include <SFML/Graphics/Text.h>

typedef struct index_s
{
    int x;
    int y;
    int z;
    int m;
} index_t;

void init_index(index_t *i);

int my_strlen(const char *str);
int my_strlen_to_c(const char *str, char c);
int my_strcmp(char *str, char *dest);
int my_strcmp_to_c(char *str, char *dest, char c);
char **str_to_word_arry(char *str);
int **str_to_int_arry(char *str);
int my_get_nbr(char *char_nbr, int base);
int nbr_of_c(const char *str, char c);
int get_tab_max(char **tab);
int my_int_len(int *i);
sfText *init_text(const char *str);
char *int_to_str(int nb);
char *my_strcat(char *const dest, char *const str);

#endif /* !STR_H_ */
