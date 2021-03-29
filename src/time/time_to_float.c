/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** time_to_float
*/

#include <SFML/System/Clock.h>

float time_to_float(sfClock *time)
{
    return (sfTime_asSeconds(sfClock_getElapsedTime(time)));
}