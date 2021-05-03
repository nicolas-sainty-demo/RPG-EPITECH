/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-louis.pavlovsky
** File description:
** make_tab
*/

#include "gameplay/inventory.h"

// sfVector2f *tab_of_vector(inventory *inv)
// {
//     inv->tab_pos[0].x = 104;
//     inv->tab_pos[0].y = 252;
//     inv->tab_pos[1].x = 104;
//     inv->tab_pos[1].y = 322;
//     inv->tab_pos[2].x = 231;
//     inv->tab_pos[2].y = 122;
//     inv->tab_pos[3].x = 231;
//     inv->tab_pos[3].y = 192;
//     inv->tab_pos[4].x = 231;
//     inv->tab_pos[4].y = 262;
//     inv->tab_pos[5].x = 231;
//     inv->tab_pos[5].y = 332;
//     inv->tab_pos[6].x = 304;
//     inv->tab_pos[6].y = 122;
//     inv->tab_pos[7].x = 377;
//     inv->tab_pos[7].y = 122;
//     inv->tab_pos[8].x = 450;
//     inv->tab_pos[8].y = 122;
//     inv->tab_pos[9].x = 523;
//     inv->tab_pos[9].y = 122;
// }

// void tab_of_vector_2(inventory *inv)
// {
//     inv->tab_pos[10].x = 304;
//     inv->tab_pos[10].y = 192;
//     inv->tab_pos[11].x = 377;
//     inv->tab_pos[11].y = 192;
//     inv->tab_pos[12].x = 450;
//     inv->tab_pos[12].y = 192;
//     inv->tab_pos[13].x = 523;
//     inv->tab_pos[13].y = 192;
//     inv->tab_pos[14].x = 304;
//     inv->tab_pos[14].y = 262;
//     inv->tab_pos[15].x = 377;
//     inv->tab_pos[15].y = 262;
//     inv->tab_pos[16].x = 450;
//     inv->tab_pos[16].y = 262;
//     inv->tab_pos[17].x = 523;
//     inv->tab_pos[17].y = 262;
//     inv->tab_pos[18].x = 304;
//     inv->tab_pos[18].y = 322;
//     inv->tab_pos[19].x = 377;
//     inv->tab_pos[19].y = 322;
// }

// void tab_of_vector_3(inventory *inv)
// {
//     inv->tab_pos[20].x = 450;
//     inv->tab_pos[20].y = 322;
//     inv->tab_pos[21].x = 523;
//     inv->tab_pos[21].y = 322;
// }

// void full_tab_vector(inventory *inv)
// {
//     inv->tab_pos = malloc(sizeof(sfVector2f) * 22);
//     tab_of_vector(inv);
//     tab_of_vector_2(inv);
//     tab_of_vector_3(inv);
// }

void init_tab_vec(inventory *inv)
{
    sfVector2f inventory_space[] = {{820, 383}, {918, 383}, {1016, 383}, {1114, 383}, {1212, 383}\
    , {820, 476}, {918, 476}, {1016, 476}, {1114, 476}, {1212, 476}\
    , {820, 569}, {918, 569}, {1016, 569}, {1114, 569}, {1212, 569}\
    , {820, 622}, {918, 662}, {1016, 662}, {1114, 662}, {1212, 662}\
    , {649, 548}, {649, 641}};
    //inv->tab_pos = inventory_space;
    printf("%d\n", inv->pos_inv);
}