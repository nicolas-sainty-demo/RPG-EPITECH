/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** un_speed_time
*/

#include <SFML/System/Clock.h>
#include <SFML/System/Time.h>

void speed_of_game(float s)
{
    sfClock *all_slow = sfClock_create();

    while (sfTime_asSeconds(sfClock_getElapsedTime(all_slow)) < s) {
    }
    sfClock_destroy(all_slow);
}