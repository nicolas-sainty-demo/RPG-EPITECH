/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** enemy
*/

#include "entity.h"
#include "window_fonction.h"

void anim_enemy(entity_enemy_t *enemy)
{
    int time = (int)(time_to_float(enemy->animation_clock) * 10);
    sfIntRect rec = sfSprite_getTextureRect(enemy->sprite);

    if (time >= enemy->anime) {
        time = 0;
        sfClock_restart(enemy->animation_clock);
    }
    if (enemy->flip == sfFalse) {
        sfSprite_setTextureRect(enemy->sprite, (sfIntRect)\
        {time * rec.width, rec.height * 0, rec.width, rec.height});
    } else {
        if (rec.width < 0)
            rec.width *= -1;
        sfSprite_setTextureRect(enemy->sprite, (sfIntRect)\
        {time * rec.width + rec.width, rec.height * 0, -1 * rec.width, rec.height});
    }
}

void anim_passive(entity_passive_t *passive)
{
    int time = (int)(time_to_float(passive->animation_clock) * 10);
    sfIntRect rec = sfSprite_getTextureRect(passive->sprite);

    printf("%d %d\n", time, passive->anime);
    if (time >= passive->anime) {
        time = 0;
        sfClock_restart(passive->animation_clock);
    }
    if (passive->flip == sfFalse) {
        sfSprite_setTextureRect(passive->sprite, (sfIntRect)\
        {time * rec.width, rec.height * 0, rec.width, rec.height});
    } else {
        if (rec.width < 0)
            rec.width *= -1;
        sfSprite_setTextureRect(passive->sprite, (sfIntRect)\
        {time * rec.width + rec.width, rec.height * 4, -1 * rec.width, rec.height});
    }
}