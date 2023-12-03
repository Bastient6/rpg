/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** update_level
*/

#include "my.h"

void update_level(player_t *player)
{
    int level = player->level;
    int exp_table[5] = {40, 80, 120, 160, 200};
    while (player->exp >= exp_table[level] && level < 5) {
        level++;
        player->level = level;
    }
}
