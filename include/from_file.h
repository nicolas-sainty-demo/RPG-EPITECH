/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** from_file
*/

#ifndef FROM_FILE_H_
#define FROM_FILE_H_

#include <SFML/System/Vector2.h>

char *get_string_after_c(const char *str, const char c);
int get_the_int_after_c(const char *str, const char c);
sfVector2i get_the_vector_i_after_c(const char *str, const char c);

#endif /* !FROM_FILE_H_ */
