/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** enemy
*/

#include "entity.h"
#include "window_fonction.h"

static void reset_clock(int time, char anim_clock, sfClock *clock)
{
    if (time >= anim_clock) {
        time = 0;
        sfClock_restart(clock);
    }
}

static void fliping(int *rec)
{
    if (*rec < 0)
        *rec *= -1;
}

void anim_enemy(entity_enemy_t *enemy)
{
    int time = (int)(time_to_float(enemy->animation_clock) * 10);
    sfIntRect rec = sfSprite_getTextureRect(enemy->sprite);

    reset_clock(time, enemy->anime, enemy->animation_clock);
    if (enemy->flip == sfFalse) {
        fliping(&rec.width);
        sfSprite_setTextureRect(enemy->sprite, (sfIntRect)\
        {time * rec.width, rec.height * 0, rec.width, rec.height});
    } else {
        fliping(&rec.width);
        sfSprite_setTextureRect(enemy->sprite, (sfIntRect)\
        {time * rec.width + rec.width, rec.height * 0, -1 * \
        rec.width, rec.height});
    }
    fliping(&rec.width);
}

void anim_passive(entity_passive_t *passive)
{
    int time = (int)(time_to_float(passive->animation_clock) * 10);
    sfIntRect rec = sfSprite_getTextureRect(passive->sprite);

    reset_clock(time, passive->anime, passive->animation_clock);
    if (passive->flip == sfFalse) {
        sfSprite_setTextureRect(passive->sprite, (sfIntRect)\
        {time * rec.width, rec.height * 0, rec.width, rec.height});
    } else {
        fliping(&rec.width);
        sfSprite_setTextureRect(passive->sprite, (sfIntRect)\
        {time * rec.width + rec.width, rec.height * 4, -1 * \
        rec.width, rec.height});
    }
}