/*
** EPITECH PROJECT, 2023
** B-MUL-200-MPL-2-1-myrpg-kylian.labrador
** File description:
** forest
*/

#include "my.h"
#include "load_file.h"

void poucet_forest(game_t *game)
{
    static int bob = 0;
    if (bob == 0) {
        game->history->scene = ROOM;
        load_file(game, "assets/fichier_sys/lopotipoucet/map_sous-sol.txt");
        game->player->pos = (sfVector2f){96, 128};
        add_description("bienvenue danslopotipoucet\npour\
        aller dans la maison ,\n approchez vous des escaliers\n \
        et appuyez sur [ESPACE]", game);
        bob = 1;
    }
    return;
}
