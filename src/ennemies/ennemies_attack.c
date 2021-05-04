/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** ennmies_attack
*/

#include "window_struc.h"
#include "collision.h"

void cooldown_ennemie(entity_enemy_t *ennemies)
{
    int time = sfTime_asSeconds(sfClock_getElapsedTime(ennemies->delay_attack));

    if (ennemies->attack == end) {
        sfClock_restart(ennemies->delay_attack);
        ennemies->attack = cooldown;
    } else if (ennemies->attack == cooldown && time >= ennemies->coold)
        ennemies->attack = ready;
}

int is_player_in_range(entity_enemy_t *ennemies, sfSprite *player)
{
    if (\
    check_if_collision_btw_square_without_rotation(ennemies->sprite, player))
        return (sfTrue);
    return (sfFalse);
}

void ennemies_deal_damage(entity_enemy_t *ennemies, player_t *player)
{
    if (ennemies->attack == ready && \
        is_player_in_range(ennemies, player->sprite)) {
        player->hp -= ennemies->damage;
        ennemies->attack = end;
    }
    cooldown_ennemie(ennemies);
}