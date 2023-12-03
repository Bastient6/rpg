/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** set_music
*/

#include "my.h"

void set_music(game_t *game, int volume)
{
    if (volume == 0)
        sfMusic_setVolume(game->music, 0);
    sfMusic_setVolume(game->music, sfMusic_getVolume(game->music) + volume);
}
