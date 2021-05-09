/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** free_res
*/

#ifndef FREE_RES_H_
#define FREE_RES_H_

#include "window_struc.h"

void free_map(map_t *map);
void free_items_on_ground(items_t **item);
void free_ennemie(entity_enemy_t *ennemies);
void free_tab_ennemies(entity_enemy_t **ennemies);
void free_entity_passive(entity_passive_t *entity);
void free_tab_entity_passive(entity_passive_t **entity);
void free_player(player_t *player);

void reset_scene_struct(the_window *windows, bool is_reset, char *path);

#endif /* !FREE_RES_H_ */
