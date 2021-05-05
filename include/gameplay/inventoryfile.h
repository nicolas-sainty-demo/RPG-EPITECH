/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** inventoyfile
*/

#ifndef INVENTORYFILE_H_
#define INVENTORYFILE_H_

#include <SFML/Graphics.h>

#define USE_KEY 1
#define SELECT_KEY 2
#define DROP_KEY 3

const sfVector2f inventory_space[] = {{-139, -158}, {-41, -158}, {57, -158}, {155, -158}, {253, -158}\
, {-139, -62}, {-41, -62}, {57, -62}, {155, -62}, {253, -62}\
, {-139, 34}, {-41, 34}, {57, 34}, {155, 34}, {253, 34}\
, {-139, 130}, {-41, 130}, {57, 130}, {155, 130}, {253, 130}\
, {-310, 17}, {-310, 113}};

const sfVector2f selec_space = {-282, -316};

const char food_list[] = {34, '#', '$'};

const char armor_list[] = {37, '&'};

const char gun_list[] = {39, 40};

#endif /* !INVENTORYFILE_H_ */
