/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** help_fonction
*/

#include "my.h"

void full_fonction(game_t *game)
{
    if (game->full == 1) {
        sfRenderWindow_close(game->window);
        game->window = create_window();
        game->full = 0;
        game->state = GAME;
        return;
    } else if (game->full == 0) {
        sfRenderWindow_close(game->window);
        game->window = create_window_full();
        game->full = 1;
        game->state = GAME;
        return;
    }
}
