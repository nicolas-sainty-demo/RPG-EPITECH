/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** entity
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Clock.h>

typedef struct quest
{
    char *dialoge;
    char *item_need;
    int xp_win;
} quest_t;

typedef struct entity_passive
{
    quest_t quest;
    char **conversation;
    sfSprite *sprite;
    char anime;
    sfClock *animation_clock;
    sfBool flip;
    int type;
    int hp;
    int speed;
    int damage;
} entity_passive_t;

enum state_ennemies
{
    passive,
    movement,
    attack
};

enum attack_ennemies
{
    ready,
    launch,
    end,
    cooldown
};

typedef struct entity_enemy
{
    sfSprite *sprite;
    char anime;
    int type;
    int radius;
    int hp;
    int hp_max;
    int speed;
    int damage;
    int coold;
    enum attack_ennemies attack;
    enum state_ennemies state;
    sfVector2f current_pos;
    sfVector2f speed_vector;
    sfClock *animation_clock;
    sfClock *delay_attack;
    sfBool flip;
} entity_enemy_t;

void anim_enemy(entity_enemy_t *enemy);
void anim_passive(entity_passive_t *passive);

#endif /* !ENTITY_H_ */
