/*
** EPITECH PROJECT, 2023
** rpg
** File description:
** annimation_up
*/

#include "my.h"

void annimation(game_t *game)
{
    game->player->rect.left += 64;
    if (game->player->rect.left >= 576)
        game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}
