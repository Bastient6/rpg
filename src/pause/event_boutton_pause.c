/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** event_boutton
*/

#include "my.h"

void resume(game_t *game)
{
    game->state = GAME;
}

void option_but(game_t *game)
{
    game->state = OPTION;
}

void quit(game_t *game)
{
    game->state = QUIT;
}

void setting(game_t *game)
{
    game->state = SETTING;
}
