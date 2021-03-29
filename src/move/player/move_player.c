/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** move_player
*/

#include "window_fonction.h"
#include "map.h"
#include <SFML/Graphics/View.h>

int player_colition_map(scene_t *scene);

static int move_bot(the_window *windows, float movement)
{
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        windows->scene->player->anime = player_run_bot;
        sfSprite_move(windows->scene->player->sprite, \
        (sfVector2f){0, movement * 1});
        return (1);
    }
    return (0);
}

static int move_top(the_window *windows, float movement)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        windows->scene->player->anime = player_run_top;
        sfSprite_move(windows->scene->player->sprite, \
        (sfVector2f){0, movement * -1});
        return (1);
    }
    return (0);
}

static int move_right(the_window *windows, float movement)
{
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        windows->scene->player->flip = sfFalse;
        windows->scene->player->anime = player_run;
        sfSprite_move(windows->scene->player->sprite, \
        (sfVector2f){movement * 1, 0});
        return (1);
    }
    return (0);
}

static int move_left(the_window *windows, float movement)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        windows->scene->player->flip = sfTrue;
        windows->scene->player->anime = player_run;
        sfSprite_move(windows->scene->player->sprite, \
        (sfVector2f){movement * -1, 0});
        return (1);
    }
    return (0);
}

void move_player(the_window *windows)
{
    float movement = ((float)windows->scene->player->speed / 100);
    sfVector2f player_pose = \
    sfSprite_getPosition(windows->scene->player->sprite);

    sfView_setCenter(windows->camera, \
    (sfVector2f){player_pose.x + 32, player_pose.y + 32});
    windows->scene->player->anime = player_stay;
    move_top(windows, movement);
    move_bot(windows, movement);
    if (!player_colition_map(windows->scene))
        sfSprite_setPosition(windows->scene->player->sprite, player_pose);
    player_pose = sfSprite_getPosition(windows->scene->player->sprite);
    move_right(windows, movement);
    move_left(windows, movement);
    if (!player_colition_map(windows->scene))
        sfSprite_setPosition(windows->scene->player->sprite, player_pose);
}