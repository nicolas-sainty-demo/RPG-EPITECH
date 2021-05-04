/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** path_finding
*/

#include "window_struc.h"
#include "collision.h"

sfVector2f calc_speed_vector(const int speed, const sfVector2f depart_pos\
, const sfVector2f arrival_pos);

int is_need_to_move(entity_enemy_t *enemy, sfSprite *player)
{
    if (check_if_collision_btw_circle_square(enemy->area_vision\
    , enemy->sprite, player)) {
        enemy->state = attack;
        return (1);
    }
    enemy->state = passive;
    return (0);
}

void move_the_ennemies\
(entity_enemy_t *ennemie, sfSprite *player)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfFloatRect bound_player = sfSprite_getGlobalBounds(player);

    pos_player.x -= bound_player.width/2;
    pos_player.y -= bound_player.height/2;
    ennemie->speed_vector = \
    calc_speed_vector(ennemie->speed, ennemie->current_pos, pos_player);
    ennemie->current_pos.x += ennemie->speed_vector.x;
    ennemie->current_pos.y += ennemie->speed_vector.y;
}

void move_around_the_ennemies(entity_enemy_t *ennemie, sfSprite *player)
{
    sfVector2f pos_player = sfSprite_getPosition(player);
    sfFloatRect bound_player = sfSprite_getGlobalBounds(player);

    if (!check_if_collision_btw_circle_square\
    (ennemie->area_shoot, ennemie->sprite, player)) {
        pos_player.x -= bound_player.width/2;
        pos_player.y -= bound_player.height/2;
        ennemie->speed_vector = \
        calc_speed_vector(ennemie->speed, ennemie->current_pos, pos_player);
        ennemie->current_pos.x += ennemie->speed_vector.x;
        ennemie->current_pos.y += ennemie->speed_vector.y;
    }
}

void path_fining(the_window *windows)
{
    for (int i = 0; windows->scene->enemy[i]; i++) {
        is_need_to_move(windows->scene->enemy[i], \
        windows->scene->player->sprite);
        if (windows->scene->enemy[i]->state == attack && \
        windows->scene->enemy[i]->type == 0) {
            move_the_ennemies(windows->scene->enemy[i], \
            windows->scene->player->sprite);
        }
        if (windows->scene->enemy[i]->state == attack && \
        windows->scene->enemy[i]->type == 1) {
            move_around_the_ennemies(windows->scene->enemy[i], \
            windows->scene->player->sprite);
        }
    }
}