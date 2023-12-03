/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** chaperon_map
*/

#include "my.h"
#include "load_file.h"

void petit_cochon_map(game_t *game)
{
    static int cochon = 0;
    if (cochon == 0) {
        load_file(game, "assets/fichier_sys/petit_cochon.txt");
        game->player->pos = (sfVector2f){135,150};
        cochon = 1;
    }
    return;
}
