/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** chaperon_map
*/

#include "my.h"
#include "load_file.h"

void chaperon_map(game_t *game)
{
    static int chaperon = 0;
    if (chaperon == 0) {
        load_file(game, "assets/fichier_sys/chaperon_rouge.txt");
        game->player->pos = (sfVector2f){800, 250};
        chaperon = 1;
    }
    return;
}
