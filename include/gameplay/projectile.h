/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** projectile
*/

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <SFML/System/Vector2.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Window/Event.h>
#include "projectile_struct.h"
#include "window_struc.h"

#define PATH_PROJ "./res/projectile/bullet.png"
#define RADIUS_PROJ 50
#define SPEED_PROJ 10
#define NB_PROJ 20
#define POS_INITIAL_PROJ (sfVector2f){-10, -10}

// init_part
projectile_t *init_projectile(char *path_projectile, int radius, int speed);

projectile_t **init_tab_projectile(char *const path_projectile\
, const int radius, const int speed, const int nb_of_projectiles);

//manipulate projectile

void reload_ammo(projectile_t *projectile);

void is_projectile_arrived(projectile_t *prjt, sfFloatRect bounds);

void move_projectile(projectile_t *projectile, sfFloatRect bounds_spt);

void shoot_projectile(projectile_t *projectile, \
sfVector2f init_pos, sfVector2f final_pos);

projectile_t *init_tab_projectile(char *const path_projectile\
, const int radius, const int speed, const int nb_of_projectiles);

//manipulate projectile
void update_projectile(projectile_t *projectile);

void reload_ammo(projectile_t *projectile);

void is_projectile_arrived(projectile_t *prjt, sfFloatRect bounds);

void move_projectile(projectile_t *projectile, sfFloatRect bounds_spt);

void shoot_projectile(projectile_t *projectile, \
sfVector2f init_pos, sfVector2f final_pos);

// update

void update_projectile(projectile_t *projectile);

void update_all_projectiles(projectile_t **projectile);

void event_projectile(sfEvent event, projectile_t **proj, the_window *windows);

// just draw

void draw_projectile(sfRenderWindow *win\
, projectile_t *const basic_projectile);

void draw_all_projectiles(sfRenderWindow *win\
, projectile_t *const *basic_projectile);


void free_projectile(projectile_t **projectiles);


#endif /* !PROJECTILE_H_ */
