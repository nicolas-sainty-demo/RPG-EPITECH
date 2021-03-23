/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** from_file
*/

#ifndef FROM_FILE_H_
#define FROM_FILE_H_

#include <SFML/System/Vector2.h>
#include "str.h"
#include "scene.h"

char *get_string_after_c(const char *str, const char c);
int get_the_int_after_c(const char *str, const char c);
sfVector2i get_the_vector_i_after_c(const char *str, const char c);
sfIntRect get_sf_int_rect_after_c(const char *str, const char c);
scene_t *get_scene_from_folder(const char *scene_name);
int get_player_from_file(player_t *player, char *name_of_dir);
void get_char_from_file\
(char **string, const char *name_of_dir, const char *name_of_file);
int my_reader(const char *nom, char **buffer);
sfSprite *get_sprite_after_c(const char *str, const char c);

#endif /* !FROM_FILE_H_ */
