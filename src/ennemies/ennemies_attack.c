/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** ennmies_attack
*/

#include "projectile.h"
#include "window_struc.h"
#include "collision.h"

void cooldown_ennemie(entity_enemy_t *ennemies)
{
    int time = \
    sfTime_asSeconds(sfClock_getElapsedTime(ennemies->delay_attack));

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

void deal_range_damage(entity_enemy_t *ennemie, player_t *player)
{
    sfVector2f pos_ennemie = sfSprite_getPosition(ennemie->sprite);
    sfVector2f pos_player = sfSprite_getPosition(player->sprite);
    sfFloatRect ennemie_bound = sfSprite_getGlobalBounds(ennemie->sprite);
    sfFloatRect player_bound = sfSprite_getGlobalBounds(player->sprite);

    pos_ennemie.x += ennemie_bound.width/2;
    pos_ennemie.y += ennemie_bound.height/2;
    pos_player.x += player_bound.width/2;
    pos_player.y += player_bound.height/2;
    if (check_if_collision_btw_circle_square(ennemie->area_shoot\
    , ennemie->sprite, player->sprite) && ennemie->proj->state == no_shoot) {
        shoot_projectile(ennemie->proj, pos_ennemie, pos_player);
    }
    if (check_if_collision_btw_circle_square(ennemie->proj->radius, \
    ennemie->proj->spt_projectile, player->sprite) && \
    ennemie->proj->state == shooted) {
        player->hp -= ennemie->damage;
        ennemie->proj->state = arrived;
    }
    update_projectile(ennemie->proj);
}

void ennemies_deal_damage(entity_enemy_t *ennemies, player_t *player)
{
    if (ennemies->attack == ready) {
        if (ennemies->type == 0 && \
        is_player_in_range(ennemies, player->sprite)) {
            player->hp -= ennemies->damage;
        }
        if (ennemies->type == 1)
            deal_range_damage(ennemies, player);
        ennemies->attack = end;
    }
    cooldown_ennemie(ennemies);
}