/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** perso_is_map
*/

#include <my.h>

void perso_is_map(game_t *game)
{
    if (game->player->pos.x >= 370 && game->player->pos.x <= 514
    && game->player->pos.y >= 45 && game->player->pos.y <= 55){
        game->state = lopotipoucet;
    }
}
