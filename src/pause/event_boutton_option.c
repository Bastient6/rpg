/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** event_boutton_option
*/

#include "my.h"

void moins(game_t *game)
{
    set_music(game, -10);
}

void plus(game_t *game)
{
    set_music(game, 10);
}

void coupe(game_t *game)
{
    set_music(game, 0);
}

void help(game_t *game)
{
    game->state = FULL;
}
